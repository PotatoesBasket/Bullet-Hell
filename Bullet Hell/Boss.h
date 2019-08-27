#pragma once
#include "Character.h"
#include "Sprite.h"
#include "BoxBoundary.h"
#include "CircleBoundary.h"
#include "BulletEmitter.h"
#include "BossData.h"
#include "Random.h"
#include <time.h>

class Boss : public Character
{
public:
	Boss(Vector2 startPos, SpriteType sprite, BossType boss);
	~Boss();

	void characterUpdate(float deltaTime) override;

protected:
	Vector3 m_startPos;
	Vector3 m_direction;
	float m_xAngle = 0;
	float m_yAngle = 0;

	//AI
	unsigned int m_currentEmitter = 0;
	bool m_canShoot = true;
	float m_shotTimer = 0;
	bool m_returnToCenter = false;

	enum MoveState
	{
		wait,
		center,
		backandforth
	};
	float m_moveTimer = 0;
	MoveState m_moveState = wait;

	enum ActState
	{
		none,
		shoot
	};
	float m_actTimer = 0;
	ActState m_actState = none;

	//Children
	std::vector<std::shared_ptr<BulletEmitter>> m_emitters;
};