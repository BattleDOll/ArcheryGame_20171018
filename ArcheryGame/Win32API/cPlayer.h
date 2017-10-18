#pragma once
#include "cImage.h"

class cPlayer
{
private:
	RECT	m_rtArrow;

	float	m_fPosX;
	float	m_fPosY;
	float	m_fCenter;

	int		m_nArrowCount;
	int		m_nMoveSpeed;
	int		m_nTargetSpeed;

	bool	m_isShoot;
	bool	m_isHit;
public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	void ArrowReSet();

	RECT GetRect() { return m_rtArrow; }
	//발사
	bool GetShoot() { return m_isShoot; }
	void SetShoot(bool shoot) { m_isShoot = shoot; }
	//맞춤
	bool GetHit() { return m_isHit; }
	void SetHit(bool hit) { m_isHit = hit; }
	// 타겟에 붙이기
	int GetTargetSpeed() { return m_nTargetSpeed; }
	void SetTargetSpeed(int speed) { m_nTargetSpeed = speed; }
	// 화살 카운트
	int GetArrowCount() { return m_nArrowCount; }

	float GetArrowCenter() { return m_fCenter; }
	void SetArrowCenter(float y) { m_fCenter = y; }
};

