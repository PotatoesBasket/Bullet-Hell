#include "Game.h"
#include "Defines.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <string>
#include <cstring>

Game::Game() {}
Game::~Game() {}

bool Game::startup()
{
	int playerHealth = 300;

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new Player("../bin/textures/placeholder/player.png", Vector2(300, 350));
	m_enemy = new Enemy("../bin/textures/placeholder/lilbigbro.png", Vector2(900, 350));
	m_enemy->scale(4, 4);

	return true;
}

void Game::shutdown()
{
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

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Game::draw()
{
	clearScreen();

	m_2dRenderer->begin();

	m_player->draw(m_2dRenderer);
	m_enemy->draw(m_2dRenderer);

	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());

	char x[50];
	sprintf_s(x, 50, "posX: %i", (int)m_player->getPosX());
	char y[50];
	sprintf_s(y, 50, "posY: %i", (int)m_player->getPosY());
	char vx[50];
	sprintf_s(vx, 50, "velX: %i", (int)m_player->getVelX());
	char vy[50];
	sprintf_s(vy, 50, "velY: %i", (int)m_player->getVelY());

	m_2dRenderer->drawText(m_font, fps, 10, 270);
	m_2dRenderer->drawText(m_font, vy, 10, 220);
	m_2dRenderer->drawText(m_font, vx, 10, 170);
	m_2dRenderer->drawText(m_font, y, 10, 120);
	m_2dRenderer->drawText(m_font, x, 10, 70);

	m_2dRenderer->drawText(m_font, "WASD - move, ESC - quit", 10, 20);

	m_2dRenderer->end();
}