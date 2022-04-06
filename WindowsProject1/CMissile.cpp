#include "pch.h"
#include "CMissile.h"

#include "CTimeManager.h"

CMissile::CMissile()
	: m_fSpeed(600.f)
	, m_fTheta(PI / 4 * 3) // 135µµ 
	, m_vDir(Vec2(0, -1))
{
	m_vDir.Nomalize();
}

CMissile::~CMissile()
{

}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	/*vPos.x += cosf(m_fTheta) * m_fSpeed * fDT;
	vPos.y -= sinf(m_fTheta) * m_fSpeed * fDT;*/
	vPos.x += m_vDir.x * m_fSpeed * fDT;
	vPos.y += m_vDir.y * m_fSpeed * fDT;

	SetPos(vPos);
}

void CMissile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Ellipse(_dc,
		(int)(vPos.x - (vScale.x / 2.f)),
		(int)(vPos.y - (vScale.y / 2.f)),
		(int)(vPos.x + (vScale.x / 2.f)),
		(int)(vPos.y + (vScale.y / 2.f))
	);
}
