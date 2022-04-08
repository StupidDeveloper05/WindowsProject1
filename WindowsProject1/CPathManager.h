#pragma once

class CPathManager
{
	SINGLE(CPathManager);
private:
	wchar_t m_strResourcePath[255];

public:
	wchar_t* GetResourcePath() { return m_strResourcePath; }

public:
	void init();
};
