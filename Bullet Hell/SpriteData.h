#pragma once

struct SpriteType
{
	SpriteType& operator=(const SpriteType& other)
	{
		filename = other.filename;
		columnCount = other.columnCount;
		rowCount = other.rowCount;
		animSpeed = other.animSpeed;
		return *this;
	}

	char* filename;
	int columnCount;
	int rowCount;
	float animSpeed;
};

const SpriteType SPRITE_NULL{ "", 1, 1 };

//Player
const SpriteType SPRITE_PLAYER_TUTORIAL			{ "../bin/textures/player_tutorial.png", 2, 1, 0.3f };
const SpriteType SPRITE_PLAYER_DEFAULT			{ "../bin/textures/player_default.png", 2, 1, 0.3f };
const SpriteType SPRITE_PLAYER_DMG1				{ "../bin/textures/player_dmg1.png", 2, 1, 0.3f };
const SpriteType SPRITE_PLAYER_DMG2				{ "../bin/textures/player_dmg2.png", 2, 1, 0.3f };

//Enemy
const SpriteType SPRITE_BOSS_1					{ "../bin/textures/flower1.png", 1, 1, 1 };

//Bullet
const SpriteType SPRITE_BULLET_PLAIN			{ "../bin/textures/bullet1.png", 2, 1, 0.3f };
const SpriteType SPRITE_BULLET_BIG				{ "../bin/textures/bullet2.png", 2, 1, 0.3f };
const SpriteType SPRITE_BULLET_BOSS1			{ "../bin/textures/bullet_boss1.png", 2, 1, 0.3f };

//Debug
const SpriteType SPRITE_EMITTER					{ "../bin/textures/emitter.png", 1, 1, 1 };