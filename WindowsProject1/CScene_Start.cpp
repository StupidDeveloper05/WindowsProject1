#include "pch.h"
#include "CScene_Start.h"

#include "CPlayer.h"
#include "CMonster.h"

#include "CCollisionManager.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	CPlayer* pObj = new CPlayer;
	pObj->SetPos(Vec2(640, 384));
	pObj->SetScale(Vec2(100.f, 100.f));

	AddObject(pObj, GROUP_TYPE::PLAYER);

	CMonster* pMon = new CMonster;
	pMon->SetPos(Vec2(640, 100));
	pMon->SetScale(Vec2(80.f, 80.f));
	pMon->SetCycleTime(0.5f);
	pMon->SetCenter(pMon->GetPos());

	AddObject(pMon, GROUP_TYPE::MONSTER);

	CCollisionManager::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
}

void CScene_Start::Exit()
{

}