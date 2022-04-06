#pragma once
#include "CObject.h"

class CPlayer :
    public CObject
{
private:
    float m_fSpeed;

public:
    virtual void update() override;

public:
    void CreateMissile();

public:
    CPlayer();
    ~CPlayer();
};
