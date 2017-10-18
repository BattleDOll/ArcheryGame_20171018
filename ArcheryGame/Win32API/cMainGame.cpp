#include "stdafx.h"
#include "cMainGame.h"
#include "cPlayer.h"
#include "cTarget.h"

cMainGame::cMainGame()
	: m_isPlaying(false)
{
	m_pPlayer = new cPlayer;
	m_pTarget = new cTarget;
}

cMainGame::~cMainGame()
{
	delete	m_pPlayer;
	delete	m_pTarget;
}

void cMainGame::Setup()
{
	m_isHit = false;

	m_nScore = 0;
	m_nTotalScore = 0;
	m_pPlayer->Setup();
	m_pTarget->Setup();
}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pPlayer->Update();
		m_pTarget->Update();

		RECT rt;
		if (IntersectRect(&rt, &m_pPlayer->GetRect(), &m_pTarget->GetRect()))
		{
			m_pPlayer->SetHit(true);
			m_pTarget->SetHit(true);
			m_isHit = true;

			m_pPlayer->SetTargetSpeed(m_pTarget->GetMoveSpeed());	

			Score();
		}	
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		Setup();
		m_isPlaying = true;
	}
}

void cMainGame::Render()
{
	// 흰색으로 이미지를 칠한다.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	if (m_isPlaying)
	{
		m_pPlayer->Render();
		m_pTarget->Render();

		// 화살 수 출력
		string str("남은 화살 : ");
		char szStr[128];

		str += itoa(m_pPlayer->GetArrowCount(), szStr, 10);
		TextOutA(g_hDC, 100, 100, str.c_str(), str.length());

		str = "남은 기회 : ";
		str += itoa(m_pTarget->GetShootChance(), szStr, 10);
		TextOutA(g_hDC, 100, 75, str.c_str(), str.length());

		str = "점수 : ";
		str += itoa(m_nConvertScore, szStr, 10);
		TextOutA(g_hDC, 100, 50, str.c_str(), str.length());

		str = "종합 점수 : ";
		str += itoa(m_nTotalScore, szStr, 10);
		TextOutA(g_hDC, 100, 20, str.c_str(), str.length());
	}
	else
	{
		TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
	}
}

void cMainGame::Score()
{
	m_nScore = m_pTarget->GetTargetCenter() - m_pPlayer->GetArrowCenter();

	if (m_nScore < 0)
	{
		m_nScore = m_nScore * - 1 ;
	}

	if (m_nScore == 0 ) 
	{
		m_nConvertScore = 10;
	}
	else if (m_nScore > 0 && m_nScore <= 10)
	{
		m_nConvertScore = 9;
	}
	else if (m_nScore > 10 && m_nScore <= 20)
	{
		m_nConvertScore = 8;
	}
	else if (m_nScore > 20 && m_nScore <= 30)
	{
		m_nConvertScore = 7;
	}
	else if (m_nScore > 30 && m_nScore <= 40)
	{
		m_nConvertScore = 6;
	}
	else
	{ 
		m_nConvertScore = 5;
	}
}
