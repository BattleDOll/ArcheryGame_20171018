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
	//�߻�
	bool GetShoot() { return m_isShoot; }
	void SetShoot(bool shoot) { m_isShoot = shoot; }
	//����
	bool GetHit() { return m_isHit; }
	void SetHit(bool hit) { m_isHit = hit; }
	// Ÿ�ٿ� ���̱�
	int GetTargetSpeed() { return m_nTargetSpeed; }
	void SetTargetSpeed(int speed) { m_nTargetSpeed = speed; }
	// ȭ�� ī��Ʈ
	int GetArrowCount() { return m_nArrowCount; }

	float GetArrowCenter() { return m_fCenter; }
	void SetArrowCenter(float y) { m_fCenter = y; }
};

