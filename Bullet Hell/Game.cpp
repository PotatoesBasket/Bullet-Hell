#include "Game.h"
#include "Defines.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <string>
#include <cstring>

Game::Game() {

}

Game::~Game() {

}

bool Game::startup() {
	
	int playerHealth = 300;

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new Player({ 0, 0 }, "..bin/textures/placeholder/ship.png", playerHealth);

	return true;
}

void Game::shutdown() {

	delete m_player;
	delete m_font;
	delete m_2dRenderer;
}

void Game::update(float deltaTime) {

	aie::Input* input = aie::Input::getInstance();

	m_player->update(deltaTime);

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Game::draw() {

	clearScreen();

	m_2dRenderer->begin();

	m_player->draw(m_2dRenderer);

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

	m_2dRenderer->drawText(m_font, vy, 0, 200);
	m_2dRenderer->drawText(m_font, vx, 0, 150);
	m_2dRenderer->drawText(m_font, y, 0, 100);
	m_2dRenderer->drawText(m_font, x, 0, 50);

	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	m_2dRenderer->end();
}