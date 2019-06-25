#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"

class Game : public aie::Application {
public:

	Game();
	virtual ~Game();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	aie::Renderer2D* m_2dRenderer;

	aie::Font* m_font;

	Player* m_player;
};