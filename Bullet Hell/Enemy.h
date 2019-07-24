#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxBoundary.h"
#include "CircleBoundary.h"

class Enemy : public GameObject
{
public:
	Enemy(const char* texture, Vector2 startPos, float width, float height, float hurtRadius);
	~Enemy() {}

	void onUpdate(float deltaTime) override {}

private:
	std::shared_ptr<Sprite> m_sprite;
	std::shared_ptr<BoxBoundary> m_boundary;
	std::shared_ptr<CircleBoundary> m_hurtbox;
};