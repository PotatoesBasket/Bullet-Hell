#pragma once
#include "Player.h"
#include "Boss.h"

class LevelBase
{
public:
	LevelBase();
	~LevelBase();

protected:
	Player* player = nullptr;
	Boss* boss = nullptr;

	float timer;
};