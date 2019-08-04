#pragma once
#include "Player.h"
#include "Boss.h"
#include "HUD.h"

class LevelBase
{
public:
	LevelBase() {}
	~LevelBase();

	virtual void update(float deltaTime) = 0;
	virtual void draw(aie::Renderer2D* renderer) = 0;

protected:
	HUD* m_hud = nullptr;
	Player* m_player = nullptr;
	Boss* m_boss = nullptr;

	float m_timer = 0;
};