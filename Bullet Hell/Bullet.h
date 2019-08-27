#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "CircleBoundary.h"
#include "BulletData.h"

/*

Bullets
- Contains bullet type data (file name, lifetime, speed)
  for every type of bullet
- Bullets are fired from the BulletEmitter object
- Bullet emitter creates pool of one bullet type on creation
  so - one emitter per bullet type

*/

class Bullet : public GameObject
{
public:
	Bullet(BulletType type, bool playerOwned);
	~Bullet() {};

	enum MoveType
	{
		straight,
		wave,
		homing
	};

	std::shared_ptr<CircleBoundary> getHitBox() { return m_hitBox; }

	/*unfinished*/
	void movement(float deltaTime);

	/*Deactivates bullet if it sticks around too long
	(ie. went offscreen), subtracts points from score.*/
	void checkLifetime(float deltaTime);

	/*Deactivates bullet object on collision with entity that
	doesn't own it, adds points to score.*/
	void checkCollision();

	void onUpdate(float deltaTime) override;

private:
	BulletType m_type = BULLET_PLAIN;
	MoveType m_movement = straight;

	//components
	std::shared_ptr<Sprite> m_texture;
	std::shared_ptr<CircleBoundary> m_hitBox;

	float m_timer = 0;
	float m_lifetime = 6;

	float m_dmgMod = 1;
	float m_spdMod = 1;

	bool m_playerOwned = false;
};