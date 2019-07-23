#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"
#include "Enemy.h"

class Game : public aie::Application
{
public:
	Game();
	virtual ~Game();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	aie::Renderer2D* m_2dRenderer = nullptr;
	aie::Font* m_font = nullptr;

	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;
};