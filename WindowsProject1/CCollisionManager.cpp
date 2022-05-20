#include "pch.h"
#include "CCollisionManager.h"

#include "CCollider.h"
#include "CObject.h"

#include "CSceneManager.h"
#include "CScene.h"

CCollisionManager::CCollisionManager()
	: m_arrCheck{}
{

}

CCollisionManager::~CCollisionManager()
{

}

void CCollisionManager::update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; ++iRow)
	{
		for (UINT iCol = 0; iCol < (UINT)GROUP_TYPE::END; ++iCol)
		{
			if (m_arrCheck[iRow] & (1 << iCol))
			{
				CollisionGroupUpdate((GROUP_TYPE)iRow, (GROUP_TYPE)iCol);
			}
		}
	}
}

void CCollisionManager::CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	// ���� �� ���
	CScene* pScene = CSceneManager::GetInst()->GetCurScene();

	// �׷� ������Ʈ ���
	const vector<CObject*>& pVecLeft = pScene->GetGroupObject(_eLeft);
	const vector<CObject*>& pVecRight = pScene->GetGroupObject(_eRight);

	// ���� �浹 �� ���ͷ����� ����
	map<ULONGLONG, bool>::iterator iter;

	for (size_t i = 0; i < pVecLeft.size(); ++i)
	{
		if (pVecLeft[i]->GetCollider() == nullptr) // �浹ü�� ���ٸ� �н�
			continue;

		for (size_t j = 0; j < pVecRight.size(); ++j)
		{
			if (pVecRight[j]->GetCollider() == nullptr || pVecLeft[i] == pVecRight[j]) // �浹ü�� ���ų� �ڱ� �ڽ��̶�� �н�
				continue;

			// �浹ü ������ ���
			CCollider* pLeftCol = pVecLeft[i]->GetCollider();
			CCollider* pRightCol = pVecRight[j]->GetCollider();

			// �浹ü ���� ���̵� ����
			COLLIDERID ID = {};
			ID.leftID = pLeftCol->GetID();
			ID.rightID = pRightCol->GetID();

			// ���̵�� ���� �浹���� �˻�
			iter = m_mapColInfo.find(ID.ID);

			// ã�� ���ߴٸ� ���Ӱ� �߰�����.
			if (iter == m_mapColInfo.end())
			{
				iter = m_mapColInfo.insert(make_pair(ID.ID, false)).first;
			}

			// �浹�ߴٸ�
			if (IsCollision(pLeftCol, pRightCol))
			{
				if (iter->second) // �������� �浹 �ߴ�.
				{
					if (pVecLeft[i]->IsDead() || pVecRight[j]->IsDead())
					{
						pLeftCol->OnCollisionExit(pRightCol);
						pRightCol->OnCollisionExit(pLeftCol);
						iter->second = false;
					}
					else
					{
						pLeftCol->OnCollision(pRightCol);
						pRightCol->OnCollision(pLeftCol);
					}
				}
				else // ó�� �浹
				{
					if (!pVecLeft[i]->IsDead() && !pVecRight[j]->IsDead())
					{
						pLeftCol->OnCollisionEnter(pRightCol);
						pRightCol->OnCollisionEnter(pLeftCol);
						iter->second = true;
					}
				}
			}
			else // �ƴ϶��
			{
				if (iter->second)
				{
					pLeftCol->OnCollisionExit(pRightCol);
					pRightCol->OnCollisionExit(pLeftCol);
					iter->second = false;
				}
			}
		}
	}
}

bool CCollisionManager::IsCollision(CCollider* pLeft, CCollider* pRight)
{
	Vec2 vLeftPos = pLeft->GetFinalPos();
	Vec2 vLeftScale = pLeft->GetScale();

	Vec2 vRightPos = pRight->GetFinalPos();
	Vec2 vRightScale = pRight->GetScale();

	if (abs(vLeftPos.x - vRightPos.x) < (vLeftScale.x + vRightScale.x) / 2.f
		&& abs(vLeftPos.y - vRightPos.y) < (vLeftScale.y + vRightScale.y) / 2.f
		)
	{
		return true;
	}

	return false;
}

void CCollisionManager::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	// ������ ��, ū�� ��
	UINT iRow = (UINT)_eLeft;
	UINT iCol = (UINT)_eRight;

	if (iRow > iCol)
	{
		iRow = (UINT)_eRight;
		iCol = (UINT)_eLeft;
	}

	if (m_arrCheck[iRow] & (1 << iCol))
	{
		m_arrCheck[iRow] &= ~(1 << iCol);
	}
	else
	{
		m_arrCheck[iRow] |= (1 << iCol);
	}
}
