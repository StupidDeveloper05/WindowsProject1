#pragma once

class CTexture;
class CCollider;

class CObject
{
private:
	Vec2		m_vPos; // 포지션
	Vec2		m_vScale; // 크기

	CCollider* m_pCollider;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }

public:
	virtual void update() = 0;
	virtual void finalupdate() final;
	virtual void render(HDC _dc);

	void component_render(HDC _dc);

public:
	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}

public:
	CObject();
	virtual ~CObject();
};

