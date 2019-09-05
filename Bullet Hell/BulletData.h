#pragma once
#include "SpriteData.h"

struct BulletType
{
	BulletType& operator=(const BulletType& type)
	{
		sprite = type.sprite;
		hitRadius = type.hitRadius;
		baseSpeed = type.baseSpeed;
		baseDamage = type.baseDamage;
		shotDelay = type.shotDelay;
		return *this;
	}

	SpriteType sprite;
	unsigned int hitRadius;
	unsigned int baseSpeed;
	unsigned int baseDamage;
	float shotDelay;
};

//player bullets
const BulletType BULLET_PLAIN = { SPRITE_BULLET_PLAIN, 3, 1000, 5, 0.2f };
const BulletType BULLET_BIG = { SPRITE_BULLET_BIG, 5, 200, 12, 0.4f };

//boss bullets
const BulletType BULLET_BOSS1 = { SPRITE_BULLET_BOSS1, 20, 500, 1, 0 };