#include "pch.h"
#include "CTexture.h"

#include "CCore.h"

CTexture::CTexture()
	: m_hDC(0)
	, m_hbitMap(0)
	, m_bitInfo{}
{
}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hbitMap);
}

void CTexture::Load(const wstring& _strFilePath)
{
	m_hbitMap = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hbitMap);

	// DC 생성
	m_hDC = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	// 비트맵 생성
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_hDC, (HBITMAP)m_hbitMap);
	DeleteObject(hOldBit);

	// 비트맵 정보 얻기
	GetObject(m_hbitMap, sizeof(BITMAP), &m_bitInfo);
}
