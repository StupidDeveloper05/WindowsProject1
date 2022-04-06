#include "pch.h"
#include "CMonster.h"
#include "CMissile.h"

#include "CTimeManager.h"

#include "CScene.h"
#include "CSceneManager.h"

CMonster::CMonster()
	: m_fSpeed(300.f)
	, m_fDistance(300.f)
	, m_vCenter(Vec2(0.f, 0.f))
	, m_iDirection(1)
	, m_fAccTime(0.0f)
	, m_fCycleTime(2.0f)
{
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

	CSceneManager::GetInst()->GetCurScene()->AddObject(pMissile, GROUP_TYPE::MONSTER_MISSILE);
}
