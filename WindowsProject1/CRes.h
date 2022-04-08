#pragma once

class CRes
{
private:
	wstring	m_strKey;
	wstring	m_strReleativePath;

public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetReleativePath(const wstring& _strPath) { m_strReleativePath = _strPath; }

	const wstring& GetKey() { return m_strKey; }
	const wstring& GetReleativePath() { return m_strReleativePath; }

public:
	CRes();
	virtual ~CRes();
};

