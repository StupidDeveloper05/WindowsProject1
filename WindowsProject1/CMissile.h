#pragma once
#include "CObject.h"

class CTexture;

class CMissile :
    public CObject
{
private:
    float   m_fSpeed;
    float   m_fTheta;
    Vec2    m_vDir;

    CTexture* m_pTex;

private:
    void SetTexture(const wstring& _strKey, const wstring& _strPath);

public:
    void SetSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }
    void SetDir(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vDir)
    {
        m_vDir = _vDir;
        m_vDir.Nomalize();
    }

public:
    virtual void update() override;
    virtual void render(HDC _dc) override;

public:
    CMissile();
    ~CMissile();

    friend class CPlayer;
    friend class CMonster;
};
