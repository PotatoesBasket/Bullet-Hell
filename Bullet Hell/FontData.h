#pragma once

struct FontType
{
	const char* filename;
	unsigned int size;
	Vector4 colour;
};

const FontType FONT_DEBUG_WHT = { "../bin/font/gameboy.ttf",			40, Vector4(1, 1, 1, 1) };
const FontType FONT_DEBUG_RED = { "../bin/font/gameboy.ttf",			40, Vector4(1, 0, 0, 1) };
const FontType FONT_DEBUG_GRN = { "../bin/font/gameboy.ttf",			40, Vector4(0, 1, 0, 1) };
const FontType FONT_DEBUG_BLU = { "../bin/font/gameboy.ttf",			40, Vector4(0, 0, 1, 1) };
const FontType FONT_DEBUG_YLW = { "../bin/font/gameboy.ttf",			40, Vector4(1, 1, 0, 1) };
const FontType FONT_DEBUG_CYA = { "../bin/font/gameboy.ttf",			40, Vector4(0, 1, 1, 1) };
const FontType FONT_DEBUG_MAG = { "../bin/font/gameboy.ttf",			40, Vector4(1, 0, 1, 1) };
const FontType FONT_DEBUG_BLK = { "../bin/font/gameboy.ttf",			40, Vector4(0, 0, 0, 1) };

const FontType FONT_TITLE			{ "../bin/font/grapesoda.ttf",		72, Vector4(0.00f, 0.00f, 0.00f, 1.00f) };
const FontType FONT_TITLE2			{ "../bin/font/04b.ttf",			96, Vector4(1.00f, 0.69f, 0.10f, 1.00f) };
const FontType FONT_SUBTITLE		{ "../bin/font/grapesoda.ttf",		36, Vector4(1.00f, 0.35f, 0.13f, 1.00f) };
const FontType FONT_MENU_STD		{ "../bin/font/grapesoda.ttf",		40, Vector4(0.50f, 0.50f, 0.50f, 1.00f) };
const FontType FONT_MENU_HOV		{ "../bin/font/grapesoda.ttf",		40, Vector4(0.00f, 0.00f, 0.00f, 1.00f) };
const FontType FONT_MENU_PRS		{ "../bin/font/grapesoda.ttf",		40, Vector4(1.00f, 0.00f, 1.00f, 1.00f) };