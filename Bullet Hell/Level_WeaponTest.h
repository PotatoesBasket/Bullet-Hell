#pragma once
#include "Player.h"
#include "Boss_Shion.h"
#include "HUD.h"

class Level_WeaponTest
{
public:
	Level_WeaponTest();
	~Level_WeaponTest();

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

private:
	Player* m_player = nullptr;
	Boss_Shion* m_shion = nullptr;
	HUD* m_hud = nullptr;
};