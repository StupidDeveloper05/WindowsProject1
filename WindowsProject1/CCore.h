#pragma once
#include <thread>

class CCore
{
	SINGLE(CCore);
private:
	HWND		m_hWnd;			// ���� �������� �ڵ�
	POINT	m_ptResolution;	// ������ ũ��

	HDC		m_hDC;	// main DC
	HDC		m_memDC; // memory DC
	HBITMAP	m_hBit;	// DC�� Bitmap

public:
	BOOL init(HWND _hWnd, POINT _ptResolution);
	void progress();

	HWND GetHandle() { return m_hWnd; }
};

