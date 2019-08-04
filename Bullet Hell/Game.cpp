#include "Game.h"
#include <Texture.h>
#include <Font.h>
#include <Input.h>
#include <string>
#include <cstring>

bool Game::startup()
{
	m_2dRenderer = new aie::Renderer2D();

	m_menu = new DebugMenu();
	m_hud = new HUD();

	m_player = new Player(Vector2(300, 350));
	m_shion = new Boss_Shion(Vector2(600, 400));

	return true;
}

void Game::shutdown()
{
	delete m_shion;
	delete m_player;
	delete m_hud;
	delete m_menu;
	delete m_2dRenderer;
}

void Game::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	GameManager& manager = GameManager::getInstance();

	switch (manager.getGameState())
	{
	case GameManager::debug_menu:
		m_menu->update(deltaTime);
		break;
	case GameManager::debug_weapontest:
		break;
	case GameManager::game:
		m_hud->update(deltaTime);
		m_player->update(deltaTime);
		m_shion->update(deltaTime);
		break;
	}

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Game::draw()
{
	clearScreen();
	GameManager& manager = GameManager::getInstance();

	m_2dRenderer->begin();

	switch (manager.getGameState())
	{
	case GameManager::debug_menu:
		m_menu->draw(m_2dRenderer);
		break;
	case GameManager::debug_weapontest:
		break;
	case GameManager::game:
		m_hud->draw(m_2dRenderer);
		m_player->draw(m_2dRenderer);
		m_shion->draw(m_2dRenderer);
		break;
	}

	m_2dRenderer->end();
}