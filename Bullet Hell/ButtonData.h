#pragma once
#include "FontData.h"
#include "SpriteData.h"

struct TextButton
{
	FontType standard;
	FontType hover;
	FontType press;
};

struct SpriteButton
{
	SpriteType standard;
	SpriteType hover;
	SpriteType press;
};

const TextButton BUTTON_TITLESCR = {
	FONT_MENU_GRY,
	FONT_MENU_WHT,
	FONT_MENU_YLW
};

const SpriteButton BUTTON_SPRITETEST = {
	SPRITE_BUTTON_1_STANDARD,
	SPRITE_BUTTON_1_HOVER,
	SPRITE_BUTTON_1_PRESS
};