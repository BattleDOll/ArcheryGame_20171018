#pragma once
#include "cImage.h"

class cPlayer;

class cTarget
{
private:
	cPlayer*		m_pPlayer;

	RECT	m_rtTarget;

	float	m_fPosX;
	float	m_fPosY;
	float	m_fCenter;

	int		m_nShootChance;
	int		m_nMoveSpeed;

	bool	m_isHit;

public:
	cTarget();
	~cTarget();

	void Setup();
	void Update();
	void Render();

	RECT GetRect() { return  m_rtTarget; }

	bool GetHit() { return m_isHit; }
	void SetHit(bool hit) { m_isHit = hit; }

	int GetMoveSpeed() { return m_nMoveSpeed; }
	void SetMoveSpeed(int speed) { m_nMoveSpeed = speed; }

	int GetShootChance() { return m_nShootChance; }
	
	float GetTargetCenter() { return m_fCenter; }
	void SetTargetCenter(float y) { m_fCenter = y; }
};

