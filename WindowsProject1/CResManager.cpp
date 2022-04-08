#include "pch.h"
#include "CResManager.h"

#include "CPathManager.h"
#include "CTexture.h"

CResManager::CResManager()
{

}

CResManager::~CResManager()
{
    map<wstring, CRes*>::iterator iter = m_mapTex.begin();
    for (; iter != m_mapTex.end(); ++iter)
    {
        delete iter->second;
    }
    m_mapTex.clear();
}

CTexture* CResManager::LoadTexture(const wstring& _strKey, const wstring& _strPath)
{
    CTexture* pTex = FindTexture(_strKey);
    if (pTex != nullptr)
     return pTex;
  
    wstring strPath = CPathManager::GetInst()->GetResourcePath();
    strPath += _strPath;

    pTex = new CTexture;
    pTex->Load(strPath);
    pTex->SetKey(_strKey);
    pTex->SetReleativePath(_strPath);

    m_mapTex.insert(make_pair(_strKey, pTex));

    return pTex;
}

CTexture* CResManager::FindTexture(const wstring& _strKey)
{
    map<wstring, CRes*>::iterator iter = m_mapTex.find(_strKey);
    if (iter == m_mapTex.end())
        return nullptr;

    return (CTexture*)iter->second;
}
