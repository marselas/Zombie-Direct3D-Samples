//-----------------------------------------------------------------------------
// File: Scene.h
//
// Desc: Holds a description for a simple scene usend in the Order Independent
//       Transparency sample.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#ifndef _SCENE_H
#define _SCENE_H

class CScene
{
public:
    CScene();

    HRESULT CALLBACK OnD3D11CreateDevice(ID3D11Device* pDevice);
    void    D3D11Render(const XMMATRIX& pmWorldViewProj, ID3D11DeviceContext* pd3dImmediateContext);
    void    OnD3D11DestroyDevice();

protected:
    struct VS_CB
    {
        XMFLOAT4X4A mWorldViewProj;
    };

    ID3D11VertexShader* m_pVertexShader;
    ID3D11InputLayout*  m_pVertexLayout;
    ID3D11Buffer*       m_pVS_CB;
    ID3D11Buffer*       m_pVB;
};

#endif