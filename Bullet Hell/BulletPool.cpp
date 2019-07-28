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

/*Looks for the first inactive bullet in bullet list and activates it.*/
void BulletPool::activateNext(GameObject* origin)
{
	std::vector<Bullet*>::iterator it = m_bulletList.begin();

	for (; it != m_bulletList.end(); ++it)
	{
		if ((*it)->getActiveState() == false)
		{
			(*it)->setPosition(
				origin->getGlobalTransform().translation.x,
				origin->getGlobalTransform().translation.y);
			(*it)->setActiveState(true);
			break;
		}
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