#include "Enemy.h"

Enemy::Enemy(const char* texture, Vector2 startPos, float width, float height, float hurtRadius)
{
	setPosition(startPos);

	m_sprite = std::make_shared<Sprite>(texture);
	addComponent(m_sprite);

	m_boundary = std::make_shared<BoxBoundary>(startPos, startPos + Vector2(width, height));
	addComponent(m_boundary);

	m_hurtbox = std::make_shared<CircleBoundary>(startPos, hurtRadius);
	addComponent(m_hurtbox);

	allComponentsOn();
}