#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND m_hWnd; // 메인 윈도우의 핸들
	POINT	m_ptResolution; // 윈도우 크기

public:
	BOOL init(HWND _hWnd, POINT _ptResolution);
	void progress();
};

