#include "pch.h"
#include "CKeyManager.h"

int g_arrKey[(UINT)KEY::LAST] =
{
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',

	VK_RETURN,
	VK_SPACE,
	VK_MENU,
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	VK_CONTROL,
	VK_SHIFT
};

CKeyManager::CKeyManager()
{

}

CKeyManager::~CKeyManager()
{

}

void CKeyManager::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		tKeyInfo tKey = { false, KEY_STATE::NONE };
		m_vecKey.push_back(tKey);
	}
}

void CKeyManager::update()
{
	HWND hWnd = GetFocus(); // ��Ŀ�̵Ǿ� �ִ��� ����.

	if (hWnd != nullptr) // ��Ŀ�� �Ǿ� �ִٸ� ����
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrKey[i]) & 0x8000)
			{
				if (m_vecKey[i].bPrevPressed)
				{
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					m_vecKey[i].bPrevPressed = true;
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
			}
			else
			{
				if (m_vecKey[i].bPrevPressed)
				{
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				m_vecKey[i].bPrevPressed = false;
			}
		}
	}
	else // �ƴϸ� �����ϰ� KEY STATE�� NONE���� �ٲ�
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].bPrevPressed = false;
			if (m_vecKey[i].eState == KEY_STATE::TAP || m_vecKey[i].eState == KEY_STATE::HOLD)
			{
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else
			{
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
}