#pragma once

typedef struct tEvent
{
	EVENT_TYPE eEvent;
	DWORD_PTR wParam;
	DWORD_PTR lParam;
};

class CEventManager
{
	SINGLE(CEventManager);
private:
	vector<tEvent> m_vecEvent;

	vector<CObject*> m_vecDead;
	
public:
	void update();

private:
	void Execute(const tEvent& _eve);

public:
	void AddEvent(const tEvent& _eve) { m_vecEvent.push_back(_eve); }
};

