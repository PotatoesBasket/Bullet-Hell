#include "Game.h"
#include "Defines.h"
#include <Texture.h>
#include <Font.h>
#include <Input.h>
#include <string>
#include <cstring>

bool Game::startup()
{
	int playerHealth = 300;

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new Player("../bin/textures/placeholder/playerAnim.png", Vector2(300, 350));
	m_enemy = new Enemy("../bin/textures/placeholder/lilbigbro.png", Vector2(900, 350), 50, 50, 0.9f, 1, 1, 1.f);
	m_enemy->scale(4, 4);
	m_test = new Enemy("../bin/textures/placeholder/numbered_grid.tga", Vector2(500, 450), 50, 50, 1.f, 8, 8, 1.f);

	butt = ResourceManager::getInstance().loadFont("../bin/font/consolas.ttf", 32);

	return true;
}

void Game::shutdown()
{
	delete m_test;
	delete m_enemy;
	delete m_player;
	delete m_font;
	delete m_2dRenderer;
}

void Game::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	m_player->update(deltaTime);
	m_enemy->update(deltaTime);
	m_test->update(deltaTime);

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Game::draw()
{
	clearScreen();

	m_2dRenderer->begin();

	m_player->draw(m_2dRenderer);
	m_enemy->draw(m_2dRenderer);
	m_test->draw(m_2dRenderer);

	m_2dRenderer->drawText(butt->as<aie::Font>(), "WASD - move, ESC - quit", 10, 20);

	m_2dRenderer->end();
}