#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"
#include "Enemy.h"

class Game : public aie::Application
{
public:
	Game() {};
	~Game() {};

	bool startup() override;
	void shutdown() override;

	void update(float deltaTime) override;
	void draw() override;

protected:
	aie::Renderer2D* m_2dRenderer = nullptr;
	aie::Font* m_font = nullptr;

	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;
};