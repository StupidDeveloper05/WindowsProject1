#include "pch.h"
#include "CObject.h"

#include "CKeyManager.h"
#include "CTimeManager.h"

#include "CCollider.h"

CObject::CObject()
	: m_vPos(Vec2(0.f, 0.f))
	, m_vScale(Vec2(100.f, 100.f))
	, m_pCollider(nullptr)
{
}

CObject::~CObject()
{
}

void CObject::finalupdate()
{
	if (nullptr != m_pCollider)
		m_pCollider->finalupdate();
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

	component_render(_dc);
}

void CObject::component_render(HDC _dc)
{
	if (nullptr != m_pCollider)
		m_pCollider->render(_dc);
}

void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}