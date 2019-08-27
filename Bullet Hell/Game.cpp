#include "Game.h"
#include <Texture.h>
#include <Font.h>
#include <Input.h>
#include <string>
#include <cstring>

bool Game::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	m_input = aie::Input::getInstance();

	m_menu = new TitleScreen();
	m_lvl1 = new Level_WeaponTest();

	return true;
}

void Game::shutdown()
{
	delete m_lvl1;
	delete m_menu;
	delete m_2dRenderer;
}

void Game::update(float deltaTime)
{
	switch (m_manager.getGameState())
	{
	case GameManager::titleScreen:
		m_menu->update(deltaTime);
		break;
	case GameManager::debug_weapontest:
		m_lvl1->update(deltaTime);
		break;
	}

	if (m_input->isKeyDown(aie::INPUT_KEY_ESCAPE) || !m_manager.checkPlaying())
		quit();
}

void Game::draw()
{
	clearScreen();
	m_2dRenderer->begin();

	switch (m_manager.getGameState())
	{
	case GameManager::titleScreen:
		m_menu->draw(m_2dRenderer);
		break;
	case GameManager::debug_weapontest:
		m_lvl1->draw(m_2dRenderer);
		break;
	}

	m_2dRenderer->end();
}