#pragma once
#include "Character.h"
#include "Sprite.h"
#include "BoxBoundary.h"
#include "CircleBoundary.h"
#include "BulletEmitter.h"
#include "BossData.h"
#include "BulletData.h"
#include <functional>

class Boss : public Character
{
public:
	Boss(Vector2 startPos, SpriteType sprite, BossType boss);
	~Boss();

private:
	void characterUpdate(float deltaTime) override;

	void setEmitterAngle(unsigned int emitterIdx, float degrees);

	//movement choices
	enum MoveState
	{
		MoveWait,
		MoveToCenter,
		MoveHelixUp,
		MoveHelixDown,
	};
	MoveState m_moveState = MoveWait;

	//move functions
	void moveToCenter(float deltaTime);
	void moveHelixUp(float deltaTime);
	void moveHelixDown(float deltaTime);

	//shot choices
	enum ShootState
	{
		ShootNone,
		ShootSpiralCW,
		ShootSpiralCCW,
	};
	ShootState m_shootState = ShootNone;

	//shoot functions
	void shootSpiralCW();
	void shootSpiralCCW();

	//here's where I'd put my AI functions... IF I HAD ANY

	//predetermined action loop because i didn't have time to implement AI :(
	void linearActionPattern(float deltaTime);

private:
	//move values
	std::shared_ptr<CircleBoundary> m_centerTrigger;
	Vector3 m_center = Vector3{ 0, 0, 0 };
	bool m_isCentered = false;
	float m_xAngle = 0;
	float m_yAngle = 0;

	//shoot values
	std::vector<std::shared_ptr<BulletEmitter>> m_emitters;
	int m_currentEmitter = 0;
	int m_secondaryEmitter = 0;
	const float m_shotDelaySlow = 0.5f;
	const float m_shotDelayMid = 0.3f;
	const float m_shotDelayFast = 0.06f;
	float m_shotDelayTimer = 0;
	bool m_canShoot = true;
};