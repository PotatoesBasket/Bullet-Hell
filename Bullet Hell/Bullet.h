#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "CircleBoundary.h"

class Bullet : public GameObject
{
public:
	Bullet(const char* filename, float lifetime, float speed);
	~Bullet() {};

	void movement(float deltaTime);
	void checkLifetime(float deltaTime);
	void checkCollision();

	void onUpdate(float deltaTime) override;

private:
	std::shared_ptr<Sprite> m_texture;
	std::shared_ptr<CircleBoundary> m_hitBox;

	float m_speed = 10;
	float m_timer = 0;
	float m_lifetime = 0.5f;
};