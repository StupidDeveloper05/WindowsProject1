#include "pch.h"
#include "CCollider.h"

#include "CObject.h"
#include "SelectGDI.h"

UINT CCollider::g_iID = 0;

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_iID(g_iID++)
{
}

CCollider::CCollider(const CCollider& _origin)
	: m_pOwner(nullptr)
	, m_vOffset(_origin.m_vOffset)
	, m_vScale(_origin.m_vScale)
	, m_iID(g_iID++)
{
}

CCollider::~CCollider()
{
}

void CCollider::finalupdate()
{
	Vec2 vPos = m_pOwner->GetPos();
	m_vFinalPos = vPos + m_vOffset;
}

void CCollider::render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	if (m_iCol > 0)
		ePen = PEN_TYPE::RED;

	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		, (int)(m_vFinalPos.x - m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y - m_vScale.y / 2.f)
		, (int)(m_vFinalPos.x + m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y + m_vScale.y / 2.f)
		);
}

void CCollider::OnCollisionEnter(CCollider* _pOther)
{
	++m_iCol;
	m_pOwner->OnCollisionEnter(_pOther);
}

void CCollider::OnCollision(CCollider* _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void CCollider::OnCollisionExit(CCollider* _pOther)
{
	--m_iCol;
	m_pOwner->OnCollisionExit(_pOther);
}
