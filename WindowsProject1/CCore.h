#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND m_hWnd; // ���� �������� �ڵ�
	POINT	m_ptResolution; // ������ ũ��

public:
	BOOL init(HWND _hWnd, POINT _ptResolution);
	void progress();
};

