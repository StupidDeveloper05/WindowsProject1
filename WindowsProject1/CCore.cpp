#include "pch.h"
#include "CCore.h"

#include "CTimeManager.h"
#include "CKeyManager.h"

#include "CObject.h"

CObject g_Obj;

CCore::CCore()
	: m_hWnd(nullptr)
	, m_ptResolution{}
{

}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

BOOL CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	RECT rect = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, TRUE);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rect.right - rect.left, rect.bottom - rect.top, 0);

	// 더블 버퍼링
	m_hDC = GetDC(m_hWnd);

	m_memDC = CreateCompatibleDC(m_hDC);
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	
	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	// Test Object
	g_Obj.SetPos(Vec2(640, 384));
	g_Obj.SetScale(Vec2(100.f, 100.f));

	// Manager init
	CTimeManager::GetInst()->init();
	CKeyManager::GetInst()->init();

	return S_OK;
}

void CCore::progress()
{
	// Manager 업데이트
	CTimeManager::GetInst()->update();
	CKeyManager::GetInst()->update();

	// Object update
	g_Obj.update();

	// 화면 클리어
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	// 그리기 코드
	g_Obj.render(m_memDC);

	// 화면에 복사
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
}
