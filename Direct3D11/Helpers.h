//--------------------------------------------------------------------------------------
// File: Helpers.h
//
// Consolidated and centralized helper functions and glue to bridge the samples up from older code 
// Centralizes lib dependencies on other repositories so the dependencies are not hidden in project files
// 
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include <assert.h>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <codecvt>
#include <fstream>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <Wincodec.h>

#include "..\..\..\DirectXTex\DirectXTex\DirectXTex.h"
#include "..\..\..\DirectXTex\DDSTextureLoader\DDSTextureLoader.h"
#include "..\..\..\DirectXTex\WICTextureLoader\WICTextureLoader.h"
#include "..\..\..\DirectXMesh\DirectXMesh\DirectXMesh.h"

using namespace DirectX;

//--------------------------------------------------------------------------------------
// New system libs
//--------------------------------------------------------------------------------------
#pragma comment(lib, "Usp10.lib")

//--------------------------------------------------------------------------------------
// Dependencies on libs built by other repositories
//--------------------------------------------------------------------------------------
#ifdef _WIN64
#ifdef _DEBUG
#pragma comment(lib, "..\\..\\FX11\\Bin\\Desktop_2015\\x64\\Debug\\Effects11.lib")
#pragma comment(lib, "..\\..\\DXUT\\Core\\Bin\\Desktop_2015\\x64\\Debug\\DXUT.lib")
#pragma comment(lib, "..\\..\\DXUT\\Optional\\Bin\\Desktop_2015\\x64\\Debug\\DXUTOpt.lib")
#pragma comment(lib, "..\\..\\DirectXTex\\DirectXTex\\Bin\\Desktop_2015\\x64\\Debug\\DirectXTex.lib")
#pragma comment(lib, "..\\..\\DirectXMesh\\DirectXMesh\\Bin\\Desktop_2015\\x64\\Debug\\DirectXMesh.lib")
#else
#pragma comment(lib, "..\\..\\FX11\\Bin\\Desktop_2015\\x64\\Release\\Effects11.lib")
#pragma comment(lib, "..\\..\\DXUT\\Core\\Bin\\Desktop_2015\\x64\\Release\\DXUT.lib")
#pragma comment(lib, "..\\..\\DXUT\\Optional\\Bin\\Desktop_2015\\x64\\Release\\DXUTOpt.lib")
#pragma comment(lib, "..\\..\\DirectXTex\\DirectXTex\\Bin\\Desktop_2015\\x64\\Release\\DirectXTex.lib")
#pragma comment(lib, "..\\..\\DirectXMesh\\DirectXMesh\\Bin\\Desktop_2015\\x64\\Release\\DirectXMesh.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib, "..\\..\\FX11\\Bin\\Desktop_2015\\Win32\\Debug\\Effects11.lib")
#pragma comment(lib, "..\\..\\DXUT\\Core\\Bin\\Desktop_2015\\Win32\\Debug\\DXUT.lib")
#pragma comment(lib, "..\\..\\DXUT\\Optional\\Bin\\Desktop_2015\\Win32\\Debug\\DXUTOpt.lib")
#pragma comment(lib, "..\\..\\DirectXTex\\DirectXTex\\Bin\\Desktop_2015\\Win32\\Debug\\DirectXTex.lib")
#pragma comment(lib, "..\\..\\DirectXMesh\\DirectXMesh\\Bin\\Desktop_2015\\Win32\\Debug\\DirectXMesh.lib")
#else
#pragma comment(lib, "..\\..\\FX11\\Bin\\Desktop_2015\\Win32\\Release\\Effects11.lib")
#pragma comment(lib, "..\\..\\DXUT\\Core\\Bin\\Desktop_2015\\Win32\\Release\\DXUT.lib")
#pragma comment(lib, "..\\..\\DXUT\\Optional\\Bin\\Desktop_2015\\Win32\\Release\\DXUTOpt.lib")
#pragma comment(lib, "..\\..\\DirectXTex\\DirectXTex\\Bin\\Desktop_2015\\Win32\\Release\\DirectXTex.lib")
#pragma comment(lib, "..\\..\\DirectXMesh\\DirectXMesh\\Bin\\Desktop_2015\\Win32\\Release\\DirectXMesh.lib")
#endif
#endif

//--------------------------------------------------------------------------------------
// Save texture to DDS file
//--------------------------------------------------------------------------------------
inline HRESULT SaveToDDSFile(
    _In_ ID3D11DeviceContext* pContext,
    _In_ ID3D11Texture2D* pTexture,
    _In_ const WCHAR* pFilename)
{
    D3D11_MAPPED_SUBRESOURCE msr = {};
    HRESULT hr = pContext->Map(pTexture, 0, D3D11_MAP_READ, 0, &msr);
    if (FAILED(hr))
    {
        assert(0);
        return hr;
    }

    D3D11_TEXTURE2D_DESC encodedDesc = {};
    pTexture->GetDesc(&encodedDesc);
    Image image;

    image.width = encodedDesc.Width;
    image.height = encodedDesc.Height;
    image.format = encodedDesc.Format;
    image.rowPitch = msr.RowPitch;
    image.slicePitch = msr.DepthPitch;
    image.pixels = static_cast<uint8_t *>(msr.pData);

    hr = SaveToDDSFile(image, 0, pFilename);
    if (FAILED(hr))
    {
        assert(0);
    }

    pContext->Unmap(pTexture, 0);

    return hr;
}

//--------------------------------------------------------------------------------------
// Save texture to PNG file
//--------------------------------------------------------------------------------------
inline HRESULT SaveToPNGFile(
    _In_ ID3D11DeviceContext* pContext,
    _In_ ID3D11Texture2D* pTexture,
    _In_ const WCHAR* pFilename)
{
    D3D11_MAPPED_SUBRESOURCE msr = {};
    HRESULT hr = pContext->Map(pTexture, 0, D3D11_MAP_READ, 0, &msr);
    if (FAILED(hr))
    {
        assert(0);
        return hr;
    }

    D3D11_TEXTURE2D_DESC encodedDesc = {};
    pTexture->GetDesc(&encodedDesc);
    Image image;

    image.width = encodedDesc.Width;
    image.height = encodedDesc.Height;
    image.format = encodedDesc.Format;
    image.rowPitch = msr.RowPitch;
    image.slicePitch = msr.DepthPitch;
    image.pixels = static_cast<uint8_t *>(msr.pData);

    hr = SaveToWICFile(image, WIC_FLAGS_NONE, GUID_ContainerFormatPng, pFilename, &GUID_WICPixelFormat24bppBGR);
    if (FAILED(hr))
    {
        assert(0);
    }

    pContext->Unmap(pTexture, 0);

    return hr;
}

//--------------------------------------------------------------------------------------
// Load DDS, convert to specified format, and create texture and/ or texture view resources from it
// - if you don't need to convert the DDS on load, then just use the regular version(s) of this function
//--------------------------------------------------------------------------------------
inline HRESULT CreateDDSTextureFromFile(
    _In_ ID3D11Device* d3dDevice,
    _In_ DXGI_FORMAT format,
    _In_z_ const wchar_t* szFileName,
    _Outptr_opt_ ID3D11Resource** texture,
    _Outptr_opt_ ID3D11ShaderResourceView** textureView
    )
{
    TexMetadata texMetaData = {};
    ScratchImage scratchImage = {};
    HRESULT hr = LoadFromDDSFile(szFileName, DDS_FLAGS_NONE, &texMetaData, scratchImage);
    if (FAILED(hr))
    {
        assert(0);
        return hr;
    }

    ScratchImage convertedImage = {};
    hr = Convert(
        scratchImage.GetImages(),
        scratchImage.GetImageCount(),
        texMetaData,
        format,
        0, // filter
        0, // threshold
        convertedImage);
    if (FAILED(hr))
    {
        assert(0);
        return hr;
    }

    Blob blob;
    hr = SaveToDDSMemory(
        scratchImage.GetImages(),
        scratchImage.GetImageCount(),
        scratchImage.GetMetadata(),
        0, // flags
        blob);
    if (FAILED(hr))
    {
        assert(0);
        return hr;
    }

    hr = CreateDDSTextureFromMemory(
        d3dDevice,
        (const uint8_t *)blob.GetBufferPointer(),
        blob.GetBufferSize(),
        texture,
        textureView);
    if (FAILED(hr))
    {
        assert(0);
        return hr;
    }

    return S_OK;
}

//--------------------------------------------------------------------------------------
// Generic HLSL #include file handler
//--------------------------------------------------------------------------------------
struct IncludeHandler : public ID3DInclude
{
    STDMETHOD(Open)(THIS_ D3D_INCLUDE_TYPE IncludeType, LPCSTR pFileName, LPCVOID /*pParentData*/, LPCVOID *ppData, UINT *pBytes) override
    {
        // have we already cached the file?
        auto iter = m_includeFiles.find(pFileName);
        if (iter != m_includeFiles.end())
        {
            *ppData = iter->second.data();
            *pBytes = static_cast<UINT>(iter->second.size());
            return S_OK;
        }

        // assemble the file path
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring filepath;

        if (IncludeType == D3D_INCLUDE_LOCAL)
        {
            std::vector<WCHAR> path;
            DWORD dwBytes = GetCurrentDirectory(0, nullptr);
            path.resize(dwBytes);
            dwBytes = GetCurrentDirectory(dwBytes, path.data());
            if (!dwBytes)
            {
                assert(0);
                return E_FAIL;
            }

            std::wostringstream o;
            o << path.data() << L"\\" << converter.from_bytes(pFileName);
            filepath = o.str();
        }
        else if (IncludeType == D3D_INCLUDE_SYSTEM)
        {
            filepath = converter.from_bytes(pFileName);
        }

        // load the file
        std::ifstream file(filepath.c_str());
        if (!file)
        {
            assert(0);
            return E_FAIL;
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();

        // add to cache
        m_includeFiles[pFileName] = buffer.str();

        // return cached data
        iter = m_includeFiles.find(pFileName);
        *ppData = iter->second.data();
        *pBytes = static_cast<UINT>(iter->second.size());

        return S_OK;
    }

    STDMETHOD(Close)(THIS_ LPCVOID /*pData*/) override
    {
        // allocated data will be cleaned up when the class is destroyed
        return S_OK;
    }

private:
    std::map< std::string, std::string > m_includeFiles;
};

//--------------------------------------------------------------------------------------
// Supplemental math functions
//--------------------------------------------------------------------------------------
struct _XMFLOAT3 : public XMFLOAT3
{
    _XMFLOAT3() = default;
    _XMFLOAT3(float _x, float _y, float _z) : XMFLOAT3(_x, _y, _z) {}

    operator const float *() const
    {
        return &x;
    }
};

struct _XMFLOAT4 : public XMFLOAT4
{
    _XMFLOAT4() = default;
    _XMFLOAT4(float _x, float _y, float _z, float _w) : XMFLOAT4(_x, _y, _z, _w) {}

    operator const float *() const
    {
        return &x;
    }
};

inline DirectX::XMFLOAT3 operator+(const DirectX::XMFLOAT3 &v1, const DirectX::XMFLOAT3 &v2)
{
    return DirectX::XMFLOAT3(
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z);
}

inline DirectX::XMFLOAT3 &operator+=(DirectX::XMFLOAT3 &v1, const DirectX::XMFLOAT3 &v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return v1;
}

inline DirectX::XMFLOAT3 &operator*=(DirectX::XMFLOAT3 &v1, float f)
{
    v1.x *= f;
    v1.y *= f;
    v1.z *= f;
    return v1;
}

inline DirectX::XMFLOAT2 operator-(const DirectX::XMFLOAT2 &v1, const DirectX::XMFLOAT2 &v2)
{
    return DirectX::XMFLOAT2(
        v1.x - v2.x,
        v1.y - v2.y);
}

inline DirectX::XMFLOAT3 operator-(const DirectX::XMFLOAT3 &v1, const DirectX::XMFLOAT3 &v2)
{
    return DirectX::XMFLOAT3(
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z);
}

inline DirectX::XMFLOAT3 operator-(const DirectX::XMFLOAT3 &v)
{
    return DirectX::XMFLOAT3(- v.x, - v.y, - v.z);
}

inline DirectX::XMFLOAT3 operator*(const DirectX::XMFLOAT3 &v, float f)
{
    return DirectX::XMFLOAT3(v.x * f, v.y * f, v.z * f);
}

inline DirectX::XMFLOAT3 operator*(float f, const DirectX::XMFLOAT3 &v)
{
    return DirectX::XMFLOAT3(v.x * f, v.y * f, v.z * f);
}

inline float Length(const DirectX::XMFLOAT2 &v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}

inline float Length(const DirectX::XMFLOAT3 &v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline float Length(const DirectX::XMFLOAT4 &v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

inline DirectX::XMFLOAT2 Normalize(const DirectX::XMFLOAT2 &v)
{
    DirectX::XMFLOAT2 vReturn = v;
    float length = Length(v);
    if (length)
    {
        vReturn.x /= length;
        vReturn.y /= length;
    }
    return vReturn;
}

inline DirectX::XMFLOAT3 Normalize(const DirectX::XMFLOAT3 &v)
{
    DirectX::XMFLOAT3 vReturn = v;
    float length = Length(v);
    if (length)
    {
        vReturn.x /= length;
        vReturn.y /= length;
        vReturn.z /= length;
    }
    return vReturn;
}

inline float Dot(const DirectX::XMFLOAT2 &v1, const DirectX::XMFLOAT2 &v2)
{
    return (v1.x * v2.x + v1.y * v2.y);
}

inline float Dot(const DirectX::XMFLOAT3 &v1, const DirectX::XMFLOAT3 &v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline DirectX::XMFLOAT3 Cross(const DirectX::XMFLOAT3 &v1, const DirectX::XMFLOAT3 &v2) 
{
    return DirectX::XMFLOAT3(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x);
}
