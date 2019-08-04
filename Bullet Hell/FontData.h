#pragma once

struct FontType
{
	const char* filename;
	unsigned int size;
	Vector4 colour;
};

const FontType FONT_DEBUG_WHT = { "../bin/font/gameboy.ttf", 20, Vector4(1, 1, 1, 1) };
const FontType FONT_DEBUG_RED = { "../bin/font/gameboy.ttf", 20, Vector4(1, 0, 0, 1) };
const FontType FONT_DEBUG_GRN = { "../bin/font/gameboy.ttf", 20, Vector4(0, 1, 0, 1) };
const FontType FONT_DEBUG_BLU = { "../bin/font/gameboy.ttf", 20, Vector4(0, 0, 1, 1) };
const FontType FONT_DEBUG_YLW = { "../bin/font/gameboy.ttf", 20, Vector4(1, 1, 0, 1) };
const FontType FONT_DEBUG_CYA = { "../bin/font/gameboy.ttf", 20, Vector4(0, 1, 1, 1) };
const FontType FONT_DEBUG_MAG = { "../bin/font/gameboy.ttf", 20, Vector4(1, 0, 1, 1) };
const FontType FONT_DEBUG_BLK = { "../bin/font/gameboy.ttf", 20, Vector4(0, 0, 0, 1) };