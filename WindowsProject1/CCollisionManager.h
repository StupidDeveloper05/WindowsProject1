#pragma once

class CCollider;

union COLLIDERID
{
	struct
	{
		UINT leftID;
		UINT rightID;
	};

	ULONGLONG ID;
};

class CCollisionManager
{
	SINGLE(CCollisionManager);
private:
	map<ULONGLONG, bool>	m_mapColInfo;
	UINT					m_arrCheck[(UINT)GROUP_TYPE::END];

public:
	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);

public:
	void CollisionGroupUpdate(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	bool IsCollision(CCollider* pLeft, CCollider* pRight);
};
