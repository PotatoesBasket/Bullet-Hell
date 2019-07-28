#include "BulletEmitter.h"

BulletEmitter::BulletEmitter(const char* bulletFilename, float rotation)
{
	m_pool = std::make_shared<BulletPool>(bulletFilename, 100, 5.0f, 400.0f);
	addComponent(m_pool);

	m_test = std::make_shared<Sprite>("../bin/textures/placeholder/emitter.png");
	addComponent(m_test);
}

void BulletEmitter::fire()
{
	if (m_timer >= m_delay)
	{
		m_pool->activateNext(this);
		m_timer = 0;
	}
}

void BulletEmitter::onUpdate(float deltaTime)
{
	m_timer += deltaTime;
}