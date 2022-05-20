#include "pch.h"
#include "func.h"

#include "CEventManager.h"

void CreateObject(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent evn = { };
	evn.eEvent = EVENT_TYPE::CREATE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

	CEventManager::GetInst()->AddEvent(evn);
}

void DeleteObject(CObject* _pObj)
{
	tEvent evn = { };
	evn.eEvent = EVENT_TYPE::DELETE_OBJECT;
	evn.lParam = (DWORD_PTR)_pObj;

	CEventManager::GetInst()->AddEvent(evn);
}

void ChangeScene(SCENE_TYPE _eType)
{
	tEvent evn = { };
	evn.eEvent = EVENT_TYPE::SCENE_CHANGE;
	evn.lParam = (DWORD_PTR)_eType;

	CEventManager::GetInst()->AddEvent(evn);
}
