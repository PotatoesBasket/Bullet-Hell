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

//Character
const SpriteType SPRITE_PLAYER_DEFAULT			{ "../bin/textures/player.png", 2, 1, 1 };
const SpriteType SPRITE_BOSS_1					{ "../bin/textures/flower1.png", 1, 1, 1 };

//Bullet
const SpriteType SPRITE_BULLET_PLAIN			{ "../bin/textures/bullet.png", 1, 1, 1 };
const SpriteType SPRITE_BULLET_BIG				{ "../bin/textures/bullet2.png", 1, 1, 1 };

//UI
const SpriteType SPRITE_BUTTON_1_STANDARD		{ "../bin/textures/button_menu_default.png", 1, 1, 1 };
const SpriteType SPRITE_BUTTON_1_HOVER			{ "../bin/textures/button_menu_hover.png", 1, 1, 1 };
const SpriteType SPRITE_BUTTON_1_PRESS			{ "../bin/textures/button_menu_press.png", 1, 1, 1 };

//Pretty things
const SpriteType SPRITE_YELLOWFLOWER			{ "../bin/textures/flower2.png", 1, 1, 1 };
const SpriteType SPRITE_ROSEBLOSSOM				{ "../bin/textures/roseAni3.png", 4, 1, 0.15f };

//Backgrounds
const SpriteType SPRITE_TITLETILE				{ "../bin/textures/tile_flowers.png", 1, 1, 1 };

//Debug
const SpriteType SPRITE_EMITTER					{ "../bin/textures/emitter.png", 1, 1, 1 };