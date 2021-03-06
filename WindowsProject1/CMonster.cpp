#include "pch.h"
#include "CMonster.h"
#include "CMissile.h"

#include "CTimeManager.h"

#include "CScene.h"
#include "CSceneManager.h"

#include "CTexture.h"
#include "CResManager.h"

#include "CCollider.h"

CMonster::CMonster()
	: m_fSpeed(300.f)
	, m_fDistance(300.f)
	, m_vCenter(Vec2(0.f, 0.f))
	, m_iDirection(1)
	, m_fAccTime(0.0f)
	, m_fCycleTime(2.0f)
	, m_pTex(nullptr)
	, m_hp(5)
{
	m_pTex = CResManager::GetInst()->LoadTexture(L"Monster", L"texture\\monster.bmp");
	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(-16.f, 0.f));
	GetCollider()->SetScale(Vec2(30, 50));
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	Vec2 vPos = GetPos();
	
	vPos.x += m_fSpeed * m_iDirection * fDT;

	if (m_vCenter.x - m_fDistance / 2.f > vPos.x)
	{
		m_iDirection *= -1;
		vPos.x += m_vCenter.x - m_fDistance / 2.f - vPos.x;
	}
	else if (m_vCenter.x + m_fDistance / 2.f < vPos.x)
	{
		m_iDirection *= -1;
		vPos.x += m_vCenter.x + m_fDistance / 2.f - vPos.x;
	}

	m_fAccTime += fDT;
	if (m_fAccTime >= m_fCycleTime)
	{
		m_fAccTime -= m_fCycleTime;
		CreateMissile();
	}
	SetPos(vPos);

	finalupdate();
}

void CMonster::render(HDC _dc)
{
	Vec2 vPos = GetPos();

	TransparentBlt(_dc
		, (int)(vPos.x - m_pTex->Width() / 2.f)
		, (int)(vPos.y - m_pTex->Height() / 2.f)
		, m_pTex->Width() * 0.85
		, m_pTex->Height() * 0.85
		, m_pTex->GetDC()
		, 0, 0
		, m_pTex->Width()
		, m_pTex->Height()
		, RGB(255, 0, 255)
	);

	component_render(_dc);
}

void CMonster::CreateMissile()
{
	Vec2 vPos = GetPos();
	vPos.y += GetScale().x / 2.f;

	CMissile* pMissile = new CMissile;

	pMissile->SetPos(vPos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetSpeed(500.f);
	pMissile->SetDir(Vec2(0, 1));
	pMissile->GetCollider()->SetOffsetPos(Vec2(-4.f, 13.f));
	pMissile->SetName(L"monster missile");
	pMissile->SetFirstPos(pMissile->GetPos());
	pMissile->SetDist(500.f);

	CreateObject(pMissile, GROUP_TYPE::MONSTER_MISSILE);
}


void CMonster::OnCollisionEnter(CCollider* _pOther)
{
	if (_pOther->GetObj()->GetName() == L"player missile")
	{
		m_hp -= 1;
		if (m_hp <= 0)
		{
			DeleteObject(this);
		}
	}

}

void CMonster::OnCollision(CCollider* _pOther)
{

}

void CMonster::OnCollisionExit(CCollider* _pOther)
{

}