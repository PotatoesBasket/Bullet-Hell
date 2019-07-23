#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(const char* texture, Vector2 startPos);
	~Player() {}

	void onUpdate(float deltaTime) override;

	//debug stuff
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