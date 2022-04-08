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

	// DC ����
	m_hDC = CreateCompatibleDC(CCore::GetInst()->GetMainDC());

	// ��Ʈ�� ����
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_hDC, (HBITMAP)m_hbitMap);
	DeleteObject(hOldBit);

	// ��Ʈ�� ���� ���
	GetObject(m_hbitMap, sizeof(BITMAP), &m_bitInfo);
}
