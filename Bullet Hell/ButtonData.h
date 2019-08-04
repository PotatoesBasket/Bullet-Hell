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

const TextButton BUTTON_TEXTTEST = {
	FONT_DEBUG_WHT,
	FONT_DEBUG_MAG,
	FONT_DEBUG_YLW
};

const SpriteButton BUTTON_SPRITETEST = {
	SPRITE_BUTTON_1_STANDARD,
	SPRITE_BUTTON_1_HOVER,
	SPRITE_BUTTON_1_PRESS
};