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
	// 현재 씬 얻기
	CScene* pScene = CSceneManager::GetInst()->GetCurScene();

	// 그룹 오브젝트 얻기
	const vector<CObject*>& pVecLeft = pScene->GetGroupObject(_eLeft);
	const vector<CObject*>& pVecRight = pScene->GetGroupObject(_eRight);

	// 이전 충돌 값 이터레이터 생성
	map<ULONGLONG, bool>::iterator iter;

	for (size_t i = 0; i < pVecLeft.size(); ++i)
	{
		if (pVecLeft[i]->GetCollider() == nullptr) // 충돌체가 없다면 패스
			continue;

		for (size_t j = 0; j < pVecRight.size(); ++j)
		{
			if (pVecRight[j]->GetCollider() == nullptr || pVecLeft[i] == pVecRight[j]) // 충돌체가 없거나 자기 자신이라면 패스
				continue;

			// 충돌체 포인터 얻기
			CCollider* pLeftCol = pVecLeft[i]->GetCollider();
			CCollider* pRightCol = pVecRight[j]->GetCollider();

			// 충돌체 조합 아이디 생성
			COLLIDERID ID = {};
			ID.leftID = pLeftCol->GetID();
			ID.rightID = pRightCol->GetID();

			// 아이디로 이전 충돌정보 검색
			iter = m_mapColInfo.find(ID.ID);

			// 찾지 못했다면 새롭게 추가해줌.
			if (iter == m_mapColInfo.end())
			{
				iter = m_mapColInfo.insert(make_pair(ID.ID, false)).first;
			}

			// 충돌했다면
			if (IsCollision(pLeftCol, pRightCol))
			{
				if (iter->second) // 이전에도 충돌 했다.
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
				else // 처음 충돌
				{
					if (!pVecLeft[i]->IsDead() && !pVecRight[j]->IsDead())
					{
						pLeftCol->OnCollisionEnter(pRightCol);
						pRightCol->OnCollisionEnter(pLeftCol);
						iter->second = true;
					}
				}
			}
			else // 아니라면
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
	// 작은값 행, 큰값 열
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
