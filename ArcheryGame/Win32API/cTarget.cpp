#include "stdafx.h"
#include "cTarget.h"
#include "cPlayer.h"

cTarget::cTarget()
{
	m_pPlayer = new cPlayer;
}

cTarget::~cTarget()
{
	delete m_pPlayer;
}

void cTarget::Setup()
{
	m_rtTarget = { 1000, - 100, 1010, 0 };
	m_nShootChance = 15;
	m_nMoveSpeed = 3;
	m_isHit = false;
}

void cTarget::Update()
{
	m_rtTarget.bottom += m_nMoveSpeed;
	m_rtTarget.top += m_nMoveSpeed;

	if (m_rtTarget.top > WINSIZEY)
	{
		m_rtTarget.top = -100;
		m_rtTarget.bottom = 0;

		m_pPlayer->SetShoot(false);

		m_nShootChance--;
	}

	if (m_isHit)
	{
		m_fCenter = (m_rtTarget.top + m_rtTarget.bottom) / 2;
		m_isHit = false;
	}
}

void cTarget::Render()
{
	RectangleMake(g_hDC, m_rtTarget);
}