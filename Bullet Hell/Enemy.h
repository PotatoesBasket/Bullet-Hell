#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy(const char* texture, Vector2 startPos);
	~Enemy() {}

	void onUpdate(float deltaTime) override {}
};