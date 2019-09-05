#include "BulletPool.h"
#include "BulletData.h"

BulletPool::BulletPool(BulletType type, bool playerOwned)
{
	for (unsigned int i = 0; i < m_totalCount; ++i)
	{
		Bullet* bullet = new Bullet(type, playerOwned);
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
		if ((*it)->isActive() == false)
		{
			(*it)->resetTransform();
			(*it)->move(origin->getGlobalTransform().translation.x,
				origin->getGlobalTransform().translation.y);
			(*it)->rotate(origin->getRotation());
			(*it)->getHitBox()->earlyUpdatePosition(origin);
			(*it)->setActiveState(true);
			break;
		}
	}
}

/*Calls update on all bullets in pool.*/
void BulletPool::update(GameObject* gameObject, float deltaTime)
{
	for (auto bullet : m_bulletList)
		bullet->update(deltaTime);
}

/*Calls draw on all bullets in pool.*/
void BulletPool::draw(GameObject* gameObject, aie::Renderer2D* renderer)
{
	for (auto bullet : m_bulletList)
		bullet->draw(renderer);
}