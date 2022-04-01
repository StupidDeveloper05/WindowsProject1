#pragma once

class CTimeManager
{
	SINGLE(CTimeManager);
private:
	LARGE_INTEGER		m_llPrevCount;
	LARGE_INTEGER		m_llCurCount;
	LARGE_INTEGER		m_llFrequency;

	double			m_DT;
	double			m_dAcc;
	UINT				m_iFPS;
	UINT				m_iCallCount;

public:
	void init();
	void update();
	
	double GetDT() { return m_DT; }
	double GetfDT() { return (float)m_DT; }
};