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
	Bullet(BulletType type);
	~Bullet() {};

	void movement(float deltaTime);
	void checkLifetime(float deltaTime);
	void checkCollision();

	void onUpdate(float deltaTime) override;

private:
	BulletType m_type = BULLET_PLAIN;

	std::shared_ptr<Sprite> m_texture;
	std::shared_ptr<CircleBoundary> m_hitBox;

	float m_timer = 0;
	float m_lifetime = 6;
};