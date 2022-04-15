#pragma once

class SelectGDI
{
private:
	HDC		m_hDC;

	HPEN		m_hDefaultPen;
	HBRUSH	m_hDefaultaBrush;

public:
	SelectGDI(HDC _dc, PEN_TYPE _ePen);
	SelectGDI(HDC _dc, BRUSH_TYPE _eBrush);
	~SelectGDI();
};
