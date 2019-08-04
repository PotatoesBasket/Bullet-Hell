#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "LevelBase.h"
#include "Boss_Shion.h"
#include "DebugMenu.h"
#include "HUD.h"

class Game : public aie::Application
{
public:
	Game() {}
	~Game() {}

	bool startup() override;
	void shutdown() override;

	void update(float deltaTime) override;
	void draw() override;

private:
	enum State
	{
		debug_menu,
		debug_test_lvl_1,
		splash,
		title,
		levelSelect,
		game
	};

	State m_state = State::debug_menu;

	aie::Renderer2D* m_2dRenderer = nullptr;

	DebugMenu* m_menu = nullptr;
	HUD* m_hud = nullptr;

	Player* m_player = nullptr;
	Boss_Shion* m_shion = nullptr;
};