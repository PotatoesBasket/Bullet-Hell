#include "BulletEmitter.h"
#include <iostream>

BulletEmitter::BulletEmitter(BulletType type, bool playerOwned)
{
	m_delay = type.shotDelay;

	m_pool = std::make_shared<BulletPool>(type, playerOwned);
	addComponent(m_pool);

	m_test = std::make_shared<Sprite>(SPRITE_EMITTER);
	addComponent(m_test);
}

/*Shoots a bullet.*/
void BulletEmitter::fire()
{
	if (m_timer >= m_delay)
	{
		m_pool->activateNext(this);
		m_timer = 0;
	}
}

/*Updates timer for shot delay.*/
void BulletEmitter::onUpdate(float deltaTime)
{
	m_timer += deltaTime;
}