#include "pch.h"
#include "CMissile.h"

#include "CTimeManager.h"

#include "CTexture.h"
#include "CResManager.h"

CMissile::CMissile()
	: m_fSpeed(600.f)
	, m_fTheta(PI / 4 * 3) // 135µµ 
	, m_vDir(Vec2(0, -1))
	, m_pTex(nullptr)
{
	m_vDir.Nomalize();
	m_pTex = CResManager::GetInst()->LoadTexture(L"Monster Fire", L"texture\\monsterfire.bmp");
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

	TransparentBlt(_dc
		, (int)(vPos.x - m_pTex->Width() / 2.f)
		, (int)(vPos.y - m_pTex->Height() / 2.f)
		, m_pTex->Width() * 0.85
		, m_pTex->Height() * 0.85
		, m_pTex->GetDC()
		, 0, 0
		, m_pTex->Width()
		, m_pTex->Height()
		, RGB(255, 0, 255)
	);
}

void CMissile::SetTexture(const wstring& _strKey, const wstring& _strPath)
{
	m_pTex = CResManager::GetInst()->LoadTexture(_strKey, _strPath);
}
