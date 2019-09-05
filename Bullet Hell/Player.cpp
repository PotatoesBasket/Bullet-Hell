#include "Player.h"
#include "ScreenData.h"
#include "GameManager.h"
#include <iostream>

Player::Player(const Vector2& startPos)
{
	initialise(startPos);
}

/*Set bullet types and inventory.*/
Player::Player(const Vector2& startPos, BulletType type1, BulletType type2,
	ItemType item1, ItemType item2, ItemType item3, ItemType item4) :
	m_shot1(type1), m_shot2(type2), m_item1(item1), m_item2(item2),
	m_item3(item3), m_item4(item4)
{
	initialise(startPos);
}

void Player::initialise(const Vector2& startPos)
{
	m_input = aie::Input::getInstance();
	GameManager::getInstance().setPlayer(this);

	//place in world
	move(startPos);

	//construct components and child objects
	m_sprite = std::make_shared<Sprite>(SPRITE_PLAYER_DEFAULT);

	m_boundary = std::make_shared<BoxBoundary>(
		startPos - Vector2(m_width * 0.5f, m_height * 0.5f),
		startPos + Vector2(m_width * 0.5f, m_height * 0.5f));
	m_hurtBox = std::make_shared<CircleBoundary>(
		startPos, m_hurtRadius);

	m_emitter1 = std::make_shared<BulletEmitter>(m_shot1, true);
	m_emitter2 = std::make_shared<BulletEmitter>(m_shot2, true);

	//add components and children
	addComponent(m_sprite);
	addComponent(m_boundary);
	addComponent(m_hurtBox);

	addChild(m_emitter1.get());
	addChild(m_emitter2.get());

	//set values
	m_health = 3;
	m_hurtBox->setOffset(Vector2(0, 10));

	m_emitter1->move(50, 30);
	m_emitter1->rotate(-90);
	m_emitter2->move(50, -30);
	m_emitter2->rotate(-90);

	//make sure relevant spritesheets are loaded
	//and stay loaded while player exists
	anim_default = std::make_shared<Sprite>(SPRITE_PLAYER_DEFAULT);
	anim_dmg1 = std::make_shared<Sprite>(SPRITE_PLAYER_DMG1);
	anim_dmg2 = std::make_shared<Sprite>(SPRITE_PLAYER_DMG2);
}

Player::~Player()
{
	GameManager::getInstance().removePlayer();
}

void Player::checkMovement(float deltaTime)
{
	if (m_input->isKeyDown(aie::INPUT_KEY_D))
	{
		move(Vector2(1, 0) * deltaTime * m_speed);
	}
	else if (m_input->isKeyDown(aie::INPUT_KEY_A))
	{
		move(Vector2(-1, 0) * deltaTime * m_speed);
	}

	if (m_input->isKeyDown(aie::INPUT_KEY_W))
	{
		move(Vector2(0, 1) * deltaTime * m_speed);
	}
	else if (m_input->isKeyDown(aie::INPUT_KEY_S))
	{
		move(Vector2(0, -1) * deltaTime * m_speed);
	}
}

void Player::checkCollision()
{
	GameManager& manager = GameManager::getInstance();

	if (manager.getBoss() != nullptr)
	{
		if (manager.getBoss()->isActive() && m_hurtBox->overlaps(manager.getBoss()->getHurtBox()))
		{
			setActiveState(false);
			manager.removePlayer();
		}
	}
}

void Player::checkFire()
{
	if (m_input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		m_emitter1->fire();
		m_emitter2->fire();
	}
}

void Player::updateAnimation()
{
	if (m_healthChanged == true)
	{
		switch (m_health)
		{
		case 3:
			m_sprite->changeSprite(SPRITE_PLAYER_DEFAULT);
			break;

		case 2:
			m_sprite->changeSprite(SPRITE_PLAYER_DMG1);
			break;

		case 1:
			m_sprite->changeSprite(SPRITE_PLAYER_DMG2);
			break;
		}
	}
	m_healthChanged = false;
}

void Player::characterUpdate(float deltaTime)
{
	updateAnimation();
	checkMovement(deltaTime);
	checkCollision();
	checkFire();
}