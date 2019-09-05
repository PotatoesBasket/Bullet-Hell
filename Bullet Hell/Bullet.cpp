#include "Bullet.h"
#include "GameManager.h"
#include "ScreenData.h"

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
	switch (m_movement)
	{
	case MoveType::straight:

		moveForward(m_type.baseSpeed * m_spdMod * deltaTime);
		break;

	case MoveType::wave:

		moveForward(m_type.baseSpeed * m_spdMod * deltaTime);
		//move() sin stuff
		break;

	case MoveType::homing:

		moveForward(m_type.baseSpeed * m_spdMod * deltaTime);
		break;
	}
}

void Bullet::checkLifetime(float deltaTime)
{
	m_timer += deltaTime;

	//deactivate
	if (m_timer >= m_lifetime || //if bullet has existed for too long
		getPosition().x < 0 - 50 || //or has left the screen boundary
		getPosition().x > SCR_WIDTH + 50 ||
		getPosition().y < 0 - 50 ||
		getPosition().y > SCR_HEIGHT + 50 )
	{
		//minus points every missed bullet from the player
		if (m_playerOwned)
			GameManager::getInstance().removePoints(10);

		//deactivate
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