#pragma once

class CScene;

class CSceneManager
{
	SINGLE(CSceneManager);
private:
	CScene*		m_arrScene[(UINT)SCENE_TYPE::END];
	CScene*		m_pCurScene;

public:
	void init();
	void update();
	void render(HDC _dc);

public:
	CScene* GetCurScene() { return m_pCurScene; }
};
