#include "Bullet.h"
#include "GameManager.h"

Bullet::Bullet(BulletType type, bool playerOwned)
{
	m_type = type;
	m_playerOwned = playerOwned;

	m_texture = std::make_shared<Sprite>(type.sprite);
	addComponent(m_texture);

	m_hitBox = std::make_shared<CircleBoundary>(getGlobalTransform(), type.hitRadius);
	addComponent(m_hitBox);
}

void Bullet::movement(float deltaTime)
{
	move(m_type.baseSpeed * m_spdMod * deltaTime, 0); //just goes left to right for now
}

void Bullet::checkLifetime(float deltaTime)
{
	m_timer += deltaTime;

	if (m_timer >= m_lifetime)
	{
		GameManager::getInstance().removePoints(10);
		m_timer = 0;
		setActiveState(false);
	}
}

void Bullet::checkCollision()
{
	GameManager& manager = GameManager::getInstance();

	//player bullets
	if (manager.getBoss() != nullptr && m_playerOwned)
	{
		if (manager.getBoss()->isActive() &&
			manager.getBoss()->getHurtBox()->overlaps(m_hitBox))
		{
			manager.addPoints(3000);
			manager.getBoss()->takeDamage(m_type.baseDamage * m_dmgMod);
			m_timer = 0;
			setActiveState(false);
		}
	}
	//enemy bullets
	else if (manager.getPlayer() != nullptr)
	{
		if (manager.getPlayer()->isActive() &&
			manager.getPlayer()->getHurtBox()->overlaps(m_hitBox))
		{
			manager.getPlayer()->takeDamage(m_type.baseDamage * m_dmgMod);
			m_timer = 0;
			setActiveState(false);
		}
	}
}

void Bullet::onUpdate(float deltaTime)
{
	movement(deltaTime);
	checkLifetime(deltaTime);
	checkCollision();
}