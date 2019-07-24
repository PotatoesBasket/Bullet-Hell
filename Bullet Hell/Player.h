#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxBoundary.h"
#include "CircleBoundary.h"

class Player : public GameObject
{
public:
	Player(const char* texture, Vector2 startPos);
	~Player() {}

	bool isAlive() const { return m_alive; }

	void checkInputs(float deltaTime);
	void checkCollisions();

	void onUpdate(float deltaTime) override;

	//debug stuff
	float getPosX() { return getGlobalTransform().translation.x; }
	float getPosY() { return getGlobalTransform().translation.y; }
	float getVelX() { return m_velocity.x; }
	float getVelY() { return m_velocity.y; }

private:
	bool m_alive = false;

	const float m_width = 55;
	const float m_height = 75;
	const float m_hurtRadius = 30;

	float m_speed = 200;
	Vector3 m_velocity{ 0, 0, 0 };
	Vector3 m_maxVelocity{ 200, 200, 0 };
	Vector3 m_acceleration{ 30, 30, 0 };

	std::shared_ptr<Sprite> m_sprite;
	std::shared_ptr<BoxBoundary> m_boundary;
	std::shared_ptr<CircleBoundary> m_hurtbox;
};