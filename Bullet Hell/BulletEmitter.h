#pragma once
#include "GameObject.h"
#include "BulletData.h"
#include "BulletPool.h"

class BulletEmitter : public GameObject
{
public:
	BulletEmitter(BulletType type, bool playerOwned);
	~BulletEmitter() {}

	/*Set the delay between firing each bullet.*/
	void setDelay(float delay) { m_delay = delay; }

	/*Fire loaded bullet type.*/
	void fire();

	void onUpdate(float deltaTime) override;

private:
	std::shared_ptr<BulletPool> m_pool;
	std::shared_ptr<Sprite> m_test;

	float m_timer = 0;
	float m_delay = 0;
};