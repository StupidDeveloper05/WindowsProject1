#include "pch.h"
#include "CPathManager.h"

CPathManager::CPathManager()
	: m_strResourcePath{}
{

}

CPathManager::~CPathManager()
{

}

void CPathManager::init()
{
	GetCurrentDirectory(255, m_strResourcePath);

	for (int i = wcslen(m_strResourcePath) - 1; i > 0; --i)
	{
		if (m_strResourcePath[i] == '\\')
		{
			m_strResourcePath[i] = '\0';
			break;
		}
	}

	wcscat_s(m_strResourcePath, L"\\bin\\Resource\\");
}
