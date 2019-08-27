#include "Level_WeaponTest.h"
#include "ScreenData.h"
#include "GameManager.h"
#include <iostream>

Level_WeaponTest::Level_WeaponTest()
{
	m_rose = new Decoration(SPRITE_ROSEBLOSSOM, Vector2(1200, 70));
	m_rose->rotate(0.9f);
	m_rose->scale(0.7f);
	addChild(m_rose);

	m_hud = new HUD();
	m_player = new Player(Vector2(300, SCR_HALFHEIGHT));
	m_boss = new Boss(Vector2(1000, 250), SPRITE_BOSS_1, BOSS_SHION);

	addChild(m_hud);
	addChild(m_player);
	addChild(m_boss);

	m_hud->setIntructionText("move - wasd, shoot - space, exit - esc");
	m_hud->setTimerText(std::to_string(420).c_str());
	m_hud->setPointsText(std::to_string(420).c_str());
}

Level_WeaponTest::~Level_WeaponTest()
{
	delete m_boss;
	delete m_player;
	delete m_hud;
}

void Level_WeaponTest::onUpdate(float deltaTime)
{
	GameManager& manager = GameManager::getInstance();

	m_timer += deltaTime;
	
	m_hud->setIntructionText("testy test");
	//m_hud->setTimerText(std::to_string(m_timer).c_str());
	//m_hud->setPointsText(std::to_string(manager.getPoints()).c_str());
}