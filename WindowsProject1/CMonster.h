#pragma once
#include "CObject.h"
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

public:
    void SetSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }
    void SetDistance(float _fDist) { m_fDistance = _fDist; }
    void SetCenter(Vec2 _vCenter) { m_vCenter = _vCenter; }
    void SetCycleTime(float _fCycleTIme) { m_fCycleTime = _fCycleTIme; }

public:
    virtual void update() override;

public:
    void CreateMissile();

public:
    CMonster();
    ~CMonster();
};
