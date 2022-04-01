#include "pch.h"
#include "CObject.h"

#include "CKeyManager.h"
#include "CTimeManager.h"

CObject::CObject()
	: m_vPos(Vec2(0.f, 0.f))
	, m_vScale(Vec2(100.f, 100.f))
{
}

CObject::~CObject()
{
}

void CObject::update()
{
	float speed = 100.f;
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= speed * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= speed * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += speed * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += speed * fDT;
	}

	SetPos(vPos);
}

void CObject::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc,
			(int)(vPos.x - (vScale.x / 2.f)),
			(int)(vPos.y - (vScale.y / 2.f)),
			(int)(vPos.x + (vScale.x / 2.f)),
			(int)(vPos.y + (vScale.y / 2.f))
		);
}
