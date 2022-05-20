#include "pch.h"
#include "CSceneManager.h"

#include "CScene.h"
#include "CScene_Start.h"

CSceneManager::CSceneManager()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{
}

CSceneManager::~CSceneManager()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
			delete m_arrScene[i];
	}
}

void CSceneManager::init()
{
	// ���⼭�� Scene�� �����ϰ� �ʱ�ȭ �ϰ�, �迭�� �־���.
	m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start");

	// ���߿� ���� Scene���� ����� ���� ���� �߰�����.

	// ���� ������ ����, ���� �Լ� ȣ��
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneManager::update()
{
	if (nullptr != m_pCurScene)
		m_pCurScene->update();
}

void CSceneManager::render(HDC _dc)
{
	if (nullptr != m_pCurScene)
		m_pCurScene->render(_dc);
}

void CSceneManager::ChangeScene(SCENE_TYPE _eType)
{
	m_pCurScene->Exit();

	m_pCurScene = m_arrScene[(UINT)_eType];

	m_pCurScene->Enter();
}
