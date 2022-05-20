#include "pch.h"
#include "CEventManager.h"

#include "CObject.h"
#include "CScene.h"
#include "CSceneManager.h"

CEventManager::CEventManager()
{

}

CEventManager::~CEventManager()
{

}

void CEventManager::update()
{
	for (size_t i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Execute(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventManager::Execute(const tEvent& _eve)
{
	switch (_eve.eEvent)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : Object Address
		// wParam : Group Type
		CObject* pNewObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;

		CSceneManager::GetInst()->GetCurScene()->AddObject(pNewObj, eType);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		CObject* pDeadObj = (CObject*)_eve.lParam;
		if (!pDeadObj->IsDead())
		{
			pDeadObj->SetDead();
			m_vecDead.push_back(pDeadObj);
		}
	}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		// lParam : Scene Type
		CSceneManager::GetInst()->ChangeScene((SCENE_TYPE)_eve.lParam);
	}
		break;
	}
}
