#pragma once
#include "cGameNode.h"

class cPlayer;
class cTarget;

class cMainGame : public cGameNode
{
private:
	bool			m_isPlaying;
	bool			m_isHit;

	cPlayer*		m_pPlayer;
	cTarget*		m_pTarget;

	int		m_nScore;
	int		m_nConvertScore;
	char	m_nTotalScore;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;

	void Score();
};