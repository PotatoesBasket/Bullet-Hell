#pragma once

struct FontType
{
	const char* filename;
	unsigned int size;
	Vector4 colour;
};

const FontType FONT_DEBUG_WHT = { "../bin/font/alkhemikal.ttf",		40, Vector4(1, 1, 1, 1) };
const FontType FONT_DEBUG_RED = { "../bin/font/alkhemikal.ttf",		40, Vector4(1, 0, 0, 1) };
const FontType FONT_DEBUG_GRN = { "../bin/font/alkhemikal.ttf",		40, Vector4(0, 1, 0, 1) };
const FontType FONT_DEBUG_BLU = { "../bin/font/alkhemikal.ttf",		40, Vector4(0, 0, 1, 1) };
const FontType FONT_DEBUG_YLW = { "../bin/font/alkhemikal.ttf",		40, Vector4(1, 1, 0, 1) };
const FontType FONT_DEBUG_CYA = { "../bin/font/alkhemikal.ttf",		40, Vector4(0, 1, 1, 1) };
const FontType FONT_DEBUG_MAG = { "../bin/font/alkhemikal.ttf",		40, Vector4(1, 0, 1, 1) };
const FontType FONT_DEBUG_BLK = { "../bin/font/alkhemikal.ttf",		40, Vector4(0, 0, 0, 1) };

const FontType FONT_TITLE_WHT = { "../bin/font/iknowaghost.ttf",	130, Vector4(1, 1, 1, 1) };
const FontType FONT_MENU_WHT  =	{ "../bin/font/grapesoda.ttf",		40, Vector4(1, 1, 1, 1) };
const FontType FONT_MENU_GRY  =	{ "../bin/font/grapesoda.ttf",		40, Vector4(0.5f, 0.5f, 0.5f, 1) };
const FontType FONT_MENU_YLW  =	{ "../bin/font/grapesoda.ttf",		40, Vector4(1, 1, 0, 1) };