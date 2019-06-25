#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(Point2D position, char* filename, int maxHealth);
	~Player();

	void update(float deltaTime) override;
	void draw(aie::Renderer2D* renderer) override;

	float getPosX() { return m_position.x; }
	float getPosY() { return m_position.y; }
	float getVelX() { return m_velocity.x; }
	float getVelY() { return m_velocity.y; }

private:
	float m_maxVelocity = 500;
	float m_maxAcceleration = 100;
	Point2D m_velocity{ 0, 0 };
	Point2D m_acceleration{ 0, 0 };
};