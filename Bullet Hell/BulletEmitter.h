#pragma once
#include "GameObject.h"
#include "BulletPool.h"

class BulletEmitter : public GameObject
{
public:
	BulletEmitter(const char* bulletFilename, float shotDelay, float rotation);
	~BulletEmitter() {}

	void fire();

	void onUpdate(float deltaTime) override;

private:
	std::shared_ptr<BulletPool> m_pool;
	std::shared_ptr<Sprite> m_test;

	float m_timer = 0;
	float m_delay = 0;
};