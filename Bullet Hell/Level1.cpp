#include "Level1.h"
#include "ScreenData.h"
#include "GameManager.h"
#include <iostream>

Level1::Level1()
{
	m_hud = new HUD();
	m_player = new Player(Vector2(200, SCR_HALFHEIGHT));
	m_boss = new Boss(Vector2(SCR_WIDTH - 300, SCR_HALFHEIGHT), SPRITE_BOSS_1, BOSS_SHION);

	addChild(m_hud);
	addChild(m_player);
	addChild(m_boss);
}

Level1::~Level1()
{
	delete m_boss;
	delete m_player;
	delete m_hud;
}

void Level1::onUpdate(float deltaTime)
{
	GameManager& manager = GameManager::getInstance();

	manager.addTime(deltaTime);
	
	m_hud->setTimerText(std::to_string(manager.getTimer()));
	m_hud->setPointsText(std::to_string(manager.getPoints()));
}