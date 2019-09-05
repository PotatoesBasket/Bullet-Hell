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

const TextButton BUTTON_TITLESCR { FONT_MENU_STD, FONT_MENU_HOV, FONT_MENU_PRS };