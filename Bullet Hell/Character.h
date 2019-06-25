#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(Point2D position, char* filename, int maxHealth) :
		GameObject(position, filename),
		m_maxHealth{ maxHealth },
		m_currentHealth{ maxHealth } {}

	virtual ~Character() {}

	virtual void update(float deltaTime) = 0;
	virtual void draw(aie::Renderer2D* renderer) = 0;

private:
	int m_maxHealth;
	int m_currentHealth;
};