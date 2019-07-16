#pragma once
#include "SpriteObject.h"

class Player : public SpriteObject
{
public:
	Player(const char* filename, int maxHealth);
	virtual ~Player() {}

	virtual void onUpdate(float deltaTime);

	float getPosX() { return getGlobalTransform().translation.x; }
	float getPosY() { return getGlobalTransform().translation.y; }
	float getVelX() { return m_velocity.x; }
	float getVelY() { return m_velocity.y; }

private:
	float speed = 200;
	Vector3 m_velocity{ 0, 0, 0 };
	Vector3 m_maxVelocity{ 200, 200, 0 };
	Vector3 m_acceleration{ 30, 30, 0 };
};