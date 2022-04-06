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
