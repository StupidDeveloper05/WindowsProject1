#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:
    float       m_fSpeed;
    CTexture*   m_pTex;
    float       m_fDelay;
    float       m_fCurrentDelay;

public:
    virtual void update() override;
    virtual void render(HDC _dc) override;

public:
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);

public:
    void CreateMissile();

public:
    CPlayer();
    ~CPlayer();
};
