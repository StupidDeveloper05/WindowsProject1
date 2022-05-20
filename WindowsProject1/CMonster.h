#pragma once
#include "CObject.h"

class CTexture;

class CMonster :
    public CObject
{
private:
    float   m_fSpeed;
    float   m_fDistance;
    Vec2    m_vCenter;
    int     m_iDirection;

    float   m_fAccTime;
    float   m_fCycleTime;

    CTexture* m_pTex;

    int     m_hp;

public:
    void SetSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }
    void SetDistance(float _fDist) { m_fDistance = _fDist; }
    void SetCenter(Vec2 _vCenter) { m_vCenter = _vCenter; }
    void SetCycleTime(float _fCycleTIme) { m_fCycleTime = _fCycleTIme; }
    void SetHP(int _hp) { m_hp = _hp; }

public:
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);

public:
    virtual void update() override;
    virtual void render(HDC _dc) override;

public:
    void CreateMissile();

public:
    CMonster();
    ~CMonster();
};
