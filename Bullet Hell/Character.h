#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "CircleBoundary.h"

class Character : public GameObject
{
public:
	Character() {}
	~Character() {}

	std::shared_ptr<CircleBoundary> getHurtBox() { return m_hurtBox; }
	void takeDamage(float damage);

	void checkLevelBoundary();

	//update for all characters
	void onUpdate(float deltaTime) override;
	//character specific update
	virtual void characterUpdate(float deltaTime) = 0;

protected:
	int m_health = 0;

	std::shared_ptr<Sprite>			m_sprite;
	std::shared_ptr<BoxBoundary>	m_boundary;
	std::shared_ptr<CircleBoundary>	m_hurtBox;
};