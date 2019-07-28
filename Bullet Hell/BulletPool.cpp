#include "BulletPool.h"

BulletPool::BulletPool(const char* filename, unsigned int maxCount, float lifetime, float speed)
{
	m_totalCount = maxCount;

	for (unsigned int i = 0; i < maxCount; ++i)
	{
		Bullet* bullet = new Bullet(filename, lifetime, speed);
		bullet->setActiveState(false);
		m_bulletList.push_back(bullet);
	}
}

BulletPool::~BulletPool()
{
	for (auto& bullet : m_bulletList)
		delete bullet;
}

void BulletPool::activateNext(GameObject* origin)
{
	if (m_activeCount < m_totalCount)
	{
		m_bulletList[m_activeCount]->setPosition(
			origin->getGlobalTransform().translation.x,
			origin->getGlobalTransform().translation.y);
		m_bulletList[m_activeCount]->setActiveState(true);
		m_bulletList[m_activeCount]->allComponentsOn();
		++m_activeCount;
	}
}

void BulletPool::update(GameObject* gameObject, float deltaTime)
{
	for (auto bullet : m_bulletList)
		bullet->update(deltaTime);
}

void BulletPool::draw(GameObject* gameObject, aie::Renderer2D* renderer)
{
	for (auto bullet : m_bulletList)
		bullet->draw(renderer);
}