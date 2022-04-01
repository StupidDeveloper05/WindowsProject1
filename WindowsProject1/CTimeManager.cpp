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
	QueryPerformanceCounter(&m_llCurCount); // 빈도당 프레임수

	m_DT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart; // 델타 타임 계산

	m_llPrevCount = m_llCurCount; // 이전 값을 현재 값으로 변경

	m_dAcc += m_DT; // 시간 누적
	++m_iCallCount; // 함수 호출 횟수
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
