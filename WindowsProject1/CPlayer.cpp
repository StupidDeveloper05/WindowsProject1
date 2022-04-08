#include "pch.h"
#include "CPlayer.h"

#include "CMissile.h"

#include "CKeyManager.h"
#include "CTimeManager.h"

#include "CScene.h"
#include "CSceneManager.h"

#include "CTexture.h"
#include "CResManager.h"

CPlayer::CPlayer()
	: m_fSpeed(300.f)
	, m_pTex(nullptr)
{
	m_pTex = CResManager::GetInst()->LoadTexture(L"Player", L"texture\\player.bmp");
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

void CPlayer::render(HDC _dc)
{
	Vec2 vPos = GetPos();

	TransparentBlt(_dc
		, (int)(vPos.x - m_pTex->Width() / 2.f)
		, (int)(vPos.y - m_pTex->Height() / 2.f)
		, m_pTex->Width()
		, m_pTex->Height()
		, m_pTex->GetDC()
		, 0, 0
		, m_pTex->Width()
		, m_pTex->Height()
		, RGB(255, 0, 255)
		);
}

void CPlayer::CreateMissile()
{
	Vec2 vPos = GetPos();

	CMissile* pMissile = new CMissile;

	pMissile->SetPos(Vec2(vPos));
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetTexture(L"Player Fire", L"texture\\playerfire.bmp");

	CSceneManager::GetInst()->GetCurScene()->AddObject(pMissile, GROUP_TYPE::PLAYER_MISSILE);
}