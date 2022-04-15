#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND		m_hWnd;			// ���� �������� �ڵ�
	POINT	m_ptResolution;	// ������ ũ��

	HDC		m_hDC;	// main DC
	HDC		m_memDC; // memory DC
	HBITMAP	m_hBit;	// DC�� Bitmap

	// ���� ����� gdi ����Ʈ
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

