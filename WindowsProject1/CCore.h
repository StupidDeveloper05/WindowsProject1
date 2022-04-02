#pragma once
#include <thread>

class CCore
{
	SINGLE(CCore);
private:
	HWND		m_hWnd;			// 메인 윈도우의 핸들
	POINT	m_ptResolution;	// 윈도우 크기

	HDC		m_hDC;	// main DC
	HDC		m_memDC; // memory DC
	HBITMAP	m_hBit;	// DC의 Bitmap

public:
	BOOL init(HWND _hWnd, POINT _ptResolution);
	void progress();

	HWND GetHandle() { return m_hWnd; }
};

