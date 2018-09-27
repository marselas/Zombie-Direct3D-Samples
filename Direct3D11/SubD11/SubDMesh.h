//--------------------------------------------------------------------------------------
// File: SubDMesh.h
//
// This class encapsulates the mesh loading and housekeeping functions for a SubDMesh.
// The mesh loads preprocessed SDKMESH files from disk and stages them for rendering.
//
// To view the mesh preprocessing code, please find the ExportSubDMesh.cpp file in the 
// samples content exporter.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "DXUT.h"
#include "SDKmesh.h"

// Maximum number of points that can be part of a subd quad.
// This includes the 4 interior points of the quad, plus the 1-ring neighborhood.
#define MAX_EXTRAORDINARY_POINTS 32

// Maximum valence we expect to encounter for extraordinary vertices
#define MAX_VALENCE 16

// Control point for a sub-d patch
struct SUBD_CONTROL_POINT
{
    XMFLOAT3 m_vPosition;
    BYTE		m_Weights[4];
    BYTE		m_Bones[4];
    XMFLOAT3 m_vNormal;      // Normal is not used for patch computation.
    XMFLOAT2 m_vUV;
    XMFLOAT3 m_vTanU;
};

//--------------------------------------------------------------------------------------
// This class handles most of the loading and conversion for a subd mesh.  It also
// creates and tracks buffers used by the mesh.
//--------------------------------------------------------------------------------------
class CSubDMesh
{
private:
    struct PatchPiece
    {
        SDKMESH_MESH*   m_pMesh;
        UINT            m_MeshIndex;

        ID3D11Buffer*   m_pExtraordinaryPatchIB;        // Index buffer for patches
        ID3D11Buffer*   m_pControlPointVB;              // Stores the control points for mesh
        ID3D11Buffer*   m_pPerPatchDataVB;              // Stores valences and prefixes on a per-patch basis
        ID3D11ShaderResourceView* m_pPerPatchDataSRV;   // Per-patch SRV
        INT             m_iPatchCount;
        INT             m_iRegularExtraodinarySplitPoint;

        ID3D11Buffer* m_pMyRegularPatchIB;
        ID3D11Buffer* m_pMyExtraordinaryPatchIB;
        ID3D11Buffer* m_pMyRegularPatchData;
        ID3D11Buffer* m_pMyExtraordinaryPatchData;

        ID3D11ShaderResourceView* m_pMyRegularPatchDataSRV;
        ID3D11ShaderResourceView* m_pMyExtraordinaryPatchDataSRV;

        std::vector<UINT> RegularPatchStart;
        std::vector<UINT> ExtraordinaryPatchStart;
        std::vector<UINT> RegularPatchCount;
        std::vector<UINT> ExtraordinaryPatchCount;

        XMFLOAT3     m_vCenter;
        XMFLOAT3     m_vExtents;
        INT             m_iFrameIndex;
    };

    struct PolyMeshPiece
    {
        SDKMESH_MESH*   m_pMesh;
        UINT            m_MeshIndex;
        INT             m_iFrameIndex;
        XMFLOAT3     m_vCenter;
        XMFLOAT3     m_vExtents;

        ID3D11Buffer*   m_pIndexBuffer;
        ID3D11Buffer*   m_pVertexBuffer;
    };

    std::vector<PatchPiece*>  m_PatchPieces;
    std::vector<PolyMeshPiece*>  m_PolyMeshPieces;

    CDXUTSDKMesh*   m_pMeshFile;

    ID3D11Buffer*   m_pPerSubsetCB;

    UINT            m_iCameraFrameIndex;

public:
    ~CSubDMesh();

    // Loading
    HRESULT     LoadSubDFromSDKMesh(ID3D11Device* pd3dDevice, const WCHAR* strFileName, const WCHAR* strAnimationFileName, const CHAR* strCameraName = "");
    void        Destroy();

    void        RenderPatchPiece_OnlyRegular(ID3D11DeviceContext* pd3dDeviceContext, int PieceIndex);
    void        RenderPatchPiece_OnlyExtraordinary(ID3D11DeviceContext* pd3dDeviceContext, int PieceIndex);
    void        RenderPolyMeshPiece(ID3D11DeviceContext* pd3dDeviceContext, int PieceIndex);

    // Per-frame update
    void        Update(const XMMATRIX& pWorld, double fTime);

    bool        GetCameraViewMatrix(XMMATRIX& pViewMatrix, XMVECTOR& pCameraPosWorld);

    FLOAT       GetAnimationDuration();

    void        GetBounds(XMFLOAT3* pvCenter, XMFLOAT3* pvExtents) const;

    // Accessors
    int         GetNumInfluences(UINT iMeshIndex)
    {
        return m_pMeshFile->GetNumInfluences(iMeshIndex);
    }
    const XMMATRIX GetInfluenceMatrix(UINT iMeshIndex, UINT iInfluence) const
    {
        return m_pMeshFile->GetMeshInfluenceMatrix(iMeshIndex, iInfluence);
    }

    int         GetPatchMeshIndex(UINT iPatchPiece) const
    {
        return m_PatchPieces[iPatchPiece]->m_MeshIndex;
    }
    size_t GetNumPatchPieces() const
    {
        return m_PatchPieces.size();
    }
    bool        GetPatchPieceTransform(UINT iPatchPiece, XMMATRIX& pTransform) const
    {
        INT iFrameIndex = m_PatchPieces[iPatchPiece]->m_iFrameIndex;
        if (iFrameIndex == -1)
        {
            pTransform = XMMatrixIdentity();
        }
        else
        {
            pTransform = m_pMeshFile->GetWorldMatrix(iFrameIndex);
        }
        return true;
    }

    int         GetPolyMeshIndex(UINT iPolyMeshPiece) const
    {
        return m_PolyMeshPieces[iPolyMeshPiece]->m_MeshIndex;
    }
    size_t GetNumPolyMeshPieces() const
    {
        return m_PolyMeshPieces.size();
    }
    bool        GetPolyMeshPieceTransform(UINT iPolyMeshPiece, XMMATRIX& pTransform) const
    {
        INT iFrameIndex = m_PolyMeshPieces[iPolyMeshPiece]->m_iFrameIndex;
        if (iFrameIndex == -1)
        {
            pTransform = XMMatrixIdentity();
        }
        else
        {
            pTransform = m_pMeshFile->GetWorldMatrix(iFrameIndex);
        }
        return true;
    }

protected:
    void SetupMaterial(ID3D11DeviceContext* pd3dDeviceContext, int MaterialID);
};
