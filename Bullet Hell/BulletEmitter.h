#pragma once
#include "GameObject.h"
#include "BulletData.h"
#include "BulletPool.h"

class BulletEmitter : public GameObject
{
public:
	BulletEmitter(BulletType type);
	~BulletEmitter() {}

	/*Set the delay between firing each bullet.*/
	void setDelay(float delay) { m_delay = delay; }
	void setTrajectory(float rotation);
	/*Fire loaded bullet type.*/
	void fire();

	void onUpdate(float deltaTime) override;

private:
	std::shared_ptr<BulletPool> m_pool;
	std::shared_ptr<Sprite> m_test;

	float m_timer = 0;
	float m_delay = 0;
};