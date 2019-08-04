#include "Level_WeaponTest.h"
#include "Boss_Shion.h"

Level_WeaponTest::Level_WeaponTest()
{
	m_hud = new HUD();
	m_player = new Player(Vector2(300, 500));
	m_shion = new Boss_Shion(Vector2(800, 500));

	m_hud->setIntruction("testing instruction poop poop");
}

Level_WeaponTest::~Level_WeaponTest()
{
	delete m_shion;
	delete m_player;
	delete m_hud;
}

void Level_WeaponTest::update(float deltaTime)
{
	m_shion->update(deltaTime);
	m_player->update(deltaTime);
	m_hud->update(deltaTime);
}

void Level_WeaponTest::draw(aie::Renderer2D* renderer)
{
	m_shion->draw(renderer);
	m_player->draw(renderer);
	m_hud->draw(renderer);
}