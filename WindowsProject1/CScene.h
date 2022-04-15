#pragma once

class CObject;

class CScene
{
private:
	wstring			m_strName;
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END];

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

public:
	virtual void update();
	virtual void render(HDC _dc);

	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eGroup) 
	{ 
		m_arrObj[(UINT)_eGroup].push_back(_pObj); 
	}
	vector<CObject*>& GetGroupObject(GROUP_TYPE _eGroup) { return m_arrObj[(UINT)_eGroup]; }
	
public:
	CScene();
	virtual ~CScene();
};

