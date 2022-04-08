#pragma once
#include "CRes.h"

class CTexture :
    public CRes
{
private:
    HDC         m_hDC;
    HBITMAP     m_hbitMap;
    BITMAP      m_bitInfo;

public:
    void Load(const wstring& _strFilePath);
    
    int Width() { return m_bitInfo.bmWidth; }
    int Height() { return m_bitInfo.bmHeight; }

    HDC GetDC() { return m_hDC; }

public:
    CTexture();
    virtual ~CTexture();
};

