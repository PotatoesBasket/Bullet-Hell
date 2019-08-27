#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "GameManager.h"
#include "TitleScreen.h"
#include "Level_WeaponTest.h"

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
	aie::Renderer2D* m_2dRenderer = nullptr;
	aie::Input* m_input = nullptr;
	GameManager& m_manager = GameManager::getInstance();

	//states
	TitleScreen* m_menu = nullptr;
	Level_WeaponTest* m_lvl1 = nullptr;
};