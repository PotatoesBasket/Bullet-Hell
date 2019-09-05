#pragma once
#include "Character.h"
#include "BoxBoundary.h"
#include "BulletEmitter.h"
#include "BulletData.h"
#include "ItemData.h"
#include <Input.h>

class Player : public Character
{
public:
	Player(const Vector2& startPos); //initialise with default values
	Player(const Vector2& startPos, BulletType type1, BulletType type2,
		ItemType item1, ItemType item2, ItemType item3, ItemType item4);
	~Player();

private:
	void checkMovement(float deltaTime);
	void checkCollision();
	void checkFire();

	void updateAnimation();
	void characterUpdate(float deltaTime) override;

private:
	void initialise(const Vector2& startPos);

	aie::Input* m_input = nullptr;

	const float m_width = 55;
	const float m_height = 75;

	float m_speed = 300;
	const float m_hurtRadius = 30;

	//Emitters
	std::shared_ptr<BulletEmitter>	m_emitter1;
	std::shared_ptr<BulletEmitter>	m_emitter2;

	//Inventory
	BulletType	m_shot1 = BULLET_PLAIN;
	BulletType	m_shot2 = BULLET_PLAIN;
	ItemType	m_item1 = ITEM_TEST;
	ItemType	m_item2 = ITEM_TEST;
	ItemType	m_item3 = ITEM_TEST;
	ItemType	m_item4 = ITEM_TEST;

	std::shared_ptr<Sprite> anim_default;
	std::shared_ptr<Sprite> anim_dmg1;
	std::shared_ptr<Sprite> anim_dmg2;
};