#include "pch.h"
#include "CTimeManager.h"

#include "CCore.h"

CTimeManager::CTimeManager()
		: m_llPrevCount{}
		, m_llCurCount{}
		, m_llFrequency{}
		, m_DT(0.)
		, m_dAcc(0.)
{
}

CTimeManager::~CTimeManager()
{

}

void CTimeManager::init()
{
	QueryPerformanceCounter(&m_llPrevCount);
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeManager::update()
{
	QueryPerformanceCounter(&m_llCurCount); // �󵵴� �����Ӽ�

	m_DT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart; // ��Ÿ Ÿ�� ���

	m_llPrevCount = m_llCurCount; // ���� ���� ���� ������ ����

	m_dAcc += m_DT; // �ð� ����
	++m_iCallCount; // �Լ� ȣ�� Ƚ��
	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;
		m_iCallCount = 0;
		m_dAcc -= 1.;

		wchar_t szBuff[100] = {};
		swprintf_s(szBuff, L"FPS : %d, DT : %f", m_iFPS, m_DT);
		SetWindowText(CCore::GetInst()->GetHandle(), szBuff);
	}
}
