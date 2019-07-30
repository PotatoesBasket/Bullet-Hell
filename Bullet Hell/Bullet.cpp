#include "Bullet.h"

Bullet::Bullet(const char* filename, float lifetime, float speed) :
	m_lifetime(lifetime), m_speed(speed)
{
	m_texture = std::make_shared<Sprite>(filename);
	addComponent(m_texture);

	m_hitBox = std::make_shared<CircleBoundary>
		(Vector2(this->getLocalTransform().translation.x,
			this->getLocalTransform().translation.y), 5.0f);
	addComponent(m_hitBox);
}

void Bullet::movement(float deltaTime)
{
	move(m_speed * deltaTime, 0); //just goes left to right for now
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