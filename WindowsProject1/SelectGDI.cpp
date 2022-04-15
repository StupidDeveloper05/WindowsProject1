#include "pch.h"
#include "SelectGDI.h"

#include "CCore.h"

SelectGDI::SelectGDI(HDC _dc, PEN_TYPE _ePen)
	: m_hDC(_dc)
{
	HPEN hPen = CCore::GetInst()->GetPen(_ePen);
	m_hDefaultPen = (HPEN)SelectObject(m_hDC, hPen);
}

SelectGDI::SelectGDI(HDC _dc, BRUSH_TYPE _eBrush)
	: m_hDC(_dc)
{
	HBRUSH hBrush = CCore::GetInst()->GetBrush(_eBrush);
	m_hDefaultaBrush = (HBRUSH)SelectObject(m_hDC, hBrush);
}

SelectGDI::~SelectGDI()
{
	SelectObject(m_hDC, m_hDefaultPen);
	SelectObject(m_hDC, m_hDefaultaBrush);
}
