#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND		m_hWnd;			// 메인 윈도우의 핸들
	POINT	m_ptResolution;	// 윈도우 크기

	HDC		m_hDC;	// main DC
	HDC		m_memDC; // memory DC
	HBITMAP	m_hBit;	// DC의 Bitmap

	// 자주 사용할 gdi 리스트
	HPEN		m_arrPen[(UINT)PEN_TYPE::END];
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];

public:
	BOOL init(HWND _hWnd, POINT _ptResolution);
	void progress();
	void CreateGDI();

	HWND GetHandle() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }

	HPEN GetPen(PEN_TYPE _ePen) { return m_arrPen[(UINT)_ePen]; }
	HBRUSH GetBrush(BRUSH_TYPE _eBrush) { return m_arrBrush[(UINT)_eBrush]; }

};

