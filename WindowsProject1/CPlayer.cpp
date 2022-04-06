#include "pch.h"
#include "CPlayer.h"

#include "CMissile.h"

#include "CKeyManager.h"
#include "CTimeManager.h"

#include "CScene.h"
#include "CSceneManager.h"

CPlayer::CPlayer()
	: m_fSpeed(300.f)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{	
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= m_fSpeed * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= m_fSpeed * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += m_fSpeed * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += m_fSpeed * fDT;
	}

	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}

	SetPos(vPos);
}

void CPlayer::CreateMissile()
{
	Vec2 vPos = GetPos();

	CMissile* pMissile = new CMissile;

	pMissile->SetPos(Vec2(vPos));
	pMissile->SetScale(Vec2(25.f, 25.f));

	CSceneManager::GetInst()->GetCurScene()->AddObject(pMissile, GROUP_TYPE::PLAYER_MISSILE);
}