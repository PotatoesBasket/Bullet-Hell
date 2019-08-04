#pragma once
#include "SpriteData.h"

struct BulletType
{
	SpriteType sprite;
	const int hitRadius;
	const int baseSpeed;
	const int baseDamage;
};

const BulletType BULLET_PLAIN = { SPRITE_BULLET_PLAIN, 3, 100, 5 };
const BulletType BULLET_BIG = { SPRITE_BULLET_BIG, 5, 60, 12 };