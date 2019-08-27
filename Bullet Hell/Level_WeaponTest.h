#pragma once
#include "Player.h"
#include "Boss.h"
#include "HUD.h"
#include "Decoration.h"

class Level_WeaponTest : public GameObject
{
public:
	Level_WeaponTest();
	~Level_WeaponTest();

	void onUpdate(float deltaTime) override;

private:
	Player* m_player = nullptr;
	Boss* m_boss = nullptr;
	HUD* m_hud = nullptr;

	Decoration* m_rose = nullptr;

	float m_timer = 0.0f;
};