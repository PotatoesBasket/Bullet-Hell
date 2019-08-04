#pragma once

struct SpriteType
{
	SpriteType& operator=(const SpriteType& other)
	{
		filename = other.filename;
		columnCount = other.columnCount;
		rowCount = other.rowCount;
		return *this;
	}

	char* filename;
	int columnCount;
	int rowCount;
};

const SpriteType SPRITE_NULL = { "", 1, 1 };

//Character
const SpriteType SPRITE_PLAYER_DEFAULT = { "../bin/textures/player.png", 2, 1 };
const SpriteType SPRITE_BOSS_1 = { "../bin/textures/nugget.png", 2, 1 };
const SpriteType SPRITE_BOSS_2 = { "../bin/textures/lilbigbro.png", 1, 1 };

//Bullet
const SpriteType SPRITE_BULLET_PLAIN = { "../bin/textures/bullet.png", 1, 1 };
const SpriteType SPRITE_BULLET_BIG = { "../bin/textures/bullet2.png", 1, 1 };

//UI
const SpriteType SPRITE_BUTTON_1_STANDARD = { "../bin/textures/button_menu_default.png", 1, 1 };
const SpriteType SPRITE_BUTTON_1_HOVER = { "../bin/textures/button_menu_hover.png", 1, 1 };
const SpriteType SPRITE_BUTTON_1_PRESS = { "../bin/textures/button_menu_press.png", 1, 1 };

//Debug
const SpriteType SPRITE_EMITTER = { "../bin/textures/emitter.png", 1, 1 };