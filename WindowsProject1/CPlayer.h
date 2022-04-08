#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:
    float m_fSpeed;
    CTexture* m_pTex;

public:
    virtual void update() override;
    virtual void render(HDC _dc) override;

public:
    void CreateMissile();

public:
    CPlayer();
    ~CPlayer();
};
