#pragma once

class CRes;
class CTexture;

class CResManager
{
	SINGLE(CResManager);
private:
	map<wstring, CRes*> m_mapTex;

public:
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strPath);
	CTexture* FindTexture(const wstring& _strKey);
};
