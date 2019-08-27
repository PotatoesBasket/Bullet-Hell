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
	m_health = 100;

	m_input = aie::Input::getInstance();
	GameManager::getInstance().setPlayer(this);

	//Place in world
	setPosition(startPos);

	//Add components
	m_sprite = std::make_shared<Sprite>(SPRITE_PLAYER_DEFAULT);
	addComponent(m_sprite);

	m_boundary = std::make_shared<BoxBoundary>(
		startPos - Vector2(m_width * 0.5f, m_height * 0.5f),
		startPos + Vector2(m_width * 0.5f, m_height * 0.5f));
	addComponent(m_boundary);

	m_hurtBox = std::make_shared<CircleBoundary>(startPos, m_hurtRadius);
	addComponent(m_hurtBox);

	m_emitter1 = std::make_shared<BulletEmitter>(m_shot1, true);
	addChild(m_emitter1.get());
	m_emitter1->move(50, 0);

	m_emitter2 = std::make_shared<BulletEmitter>(m_shot2, true);
	addChild(m_emitter2.get());
	m_emitter2->move(50, 0);
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

void Player::characterUpdate(float deltaTime)
{
	checkMovement(deltaTime);
	checkCollision();
	checkFire();
}