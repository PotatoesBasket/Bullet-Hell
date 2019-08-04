#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxBoundary.h"
#include "CircleBoundary.h"
#include "BulletEmitter.h"
#include "BossData.h"

class Boss : public GameObject
{
public:
	Boss(Vector2 startPos, SpriteType sprite, BossType boss);
	~Boss() {}

	virtual void onUpdate(float deltaTime) = 0;

protected:
	float m_actTimer = 0;

	//Children
	std::vector<std::shared_ptr<BulletEmitter>> m_emitters;

	//Components
	std::shared_ptr<Sprite> m_sprite;
	std::shared_ptr<BoxBoundary> m_boundary;
	std::shared_ptr<CircleBoundary> m_hurtbox;
};