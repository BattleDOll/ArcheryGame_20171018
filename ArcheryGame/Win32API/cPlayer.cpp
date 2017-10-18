#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
}

cPlayer::~cPlayer()
{
}

void cPlayer::Setup()
{
	m_rtArrow = { 30 - 20, WINSIZEY / 2 - 1, 30 + 20, WINSIZEY / 2 + 1 };
	m_nMoveSpeed = 20;
	m_nArrowCount = 10;
	m_isShoot = false;
	m_isHit = false;
}

void cPlayer::Update()
{
	if (!m_isShoot && m_nArrowCount >0 && g_pKeyManager->isOnceKeyDown(VK_SPACE ))
	{
		m_isShoot = true;
	}

	if (m_isShoot && !m_isHit)
	{
		m_rtArrow.left += m_nMoveSpeed;
		m_rtArrow.right += m_nMoveSpeed;

		if (m_rtArrow.left > WINSIZEX)
		{
			ArrowReSet();
		}
	}

	if (m_isHit)
	{
		m_rtArrow.left += 0;
		m_rtArrow.right += 0;
		m_rtArrow.top += m_nTargetSpeed;
		m_rtArrow.bottom += m_nTargetSpeed;

		m_fCenter = (m_rtArrow.top + m_rtArrow.bottom) / 2;
		m_isHit = false;
		  
	
		if (m_rtArrow.top > WINSIZEY)
		{
			ArrowReSet();
		}
	}
}


void cPlayer::Render()
{
	RectangleMake(g_hDC, m_rtArrow);
}

void cPlayer::ArrowReSet()
{
	m_isShoot = false;
	m_isHit = false;
	m_rtArrow.top = WINSIZEY / 2 - 1;
	m_rtArrow.bottom = WINSIZEY / 2 + 1;
	m_rtArrow.left = 10;
	m_rtArrow.right = 50;
	m_nArrowCount--;
}

