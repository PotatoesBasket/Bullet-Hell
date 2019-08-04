#include "Bullet.h"
#include "SpriteData.h"

Bullet::Bullet(BulletType type)
{
	m_baseSpeed = type.baseSpeed;
	m_baseDamage = type.baseDamage;

	m_texture = std::make_shared<Sprite>(type.sprite);
	addComponent(m_texture);

	m_hitBox = std::make_shared<CircleBoundary>(getLocalTransform(), type.hitRadius);
	addComponent(m_hitBox);
}

void Bullet::movement(float deltaTime)
{
	move(m_baseSpeed * deltaTime, 0); //just goes left to right for now
}

void Bullet::checkLifetime(float deltaTime)
{
	m_timer += deltaTime;

	if (m_timer >= m_lifetime)
	{
		m_timer = 0;
		m_active = false;
	}
}

void Bullet::checkCollision()
{
	//if (m_hitBox.get()->isInsideCircle())
}

void Bullet::onUpdate(float deltaTime)
{
	movement(deltaTime);
	checkLifetime(deltaTime);
	checkCollision();
}