#pragma once

class CObject;

class CCollider
{
private:
	static UINT g_iID;

	CObject* m_pOwner;
	Vec2		m_vOffset;
	Vec2		m_vFinalPos;
	Vec2		m_vScale;

	UINT		m_iID;
	UINT		m_iCol;

public:
	void SetOffsetPos(Vec2 _vOffset) { m_vOffset = _vOffset; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	
	Vec2 GetOffsetPos() { return m_vOffset; }
	Vec2 GetScale() { return m_vScale; }

	Vec2 GetFinalPos() { return m_vFinalPos; }

	CObject* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

public:
	void finalupdate();
	void render(HDC _dc);

public:
	void OnCollisionEnter(CCollider* _pOther);
	void OnCollision(CCollider* _pOther);
	void OnCollisionExit(CCollider* _pOther);

public:
	CCollider();
	CCollider(const CCollider& _origin);
	~CCollider();

	friend class CObject;
};
