#pragma once
#include "Player.h"
#include "Boss.h"
#include "HUD.h"
#include "Decoration.h"

class Level1 : public GameObject
{
public:
	Level1();
	~Level1();

	void onUpdate(float deltaTime) override;

private:
	Player* m_player = nullptr;
	Boss* m_boss = nullptr;
	HUD* m_hud = nullptr;

	float m_endTimer = 0;
};