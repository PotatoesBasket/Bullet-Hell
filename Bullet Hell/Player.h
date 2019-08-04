#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxBoundary.h"
#include "CircleBoundary.h"
#include "BulletEmitter.h"
#include "BulletData.h"
#include "ItemData.h"
#include <Input.h>

class Player : public GameObject
{
public:
	Player(const Vector2& startPos); //initialise with default values
	Player(const Vector2& startPos, BulletType type1, BulletType type2,
		ItemType item1, ItemType item2, ItemType item3, ItemType item4);
	~Player() {}

	bool isAlive() const { return m_active; }

	void checkMovement(float deltaTime);
	void checkFire();
	void checkCollisions();

	void onUpdate(float deltaTime) override;

private:
	aie::Input* m_input = nullptr;

	const float m_width = 55;
	const float m_height = 75;
	const float m_hurtRadius = 30;

	char m_shotToggle = 0;

	float m_speed = 200;
	Vector3 m_velocity{ 0, 0, 0 };
	Vector3 m_maxVelocity{ 200, 200, 0 };
	Vector3 m_acceleration{ 30, 30, 0 };

	//Children
	std::shared_ptr<BulletEmitter> m_emitter1;
	std::shared_ptr<BulletEmitter> m_emitter2;

	//Components
	std::shared_ptr<Sprite> m_sprite;
	std::shared_ptr<BoxBoundary> m_boundary;
	std::shared_ptr<CircleBoundary> m_hurtbox;

	//Inventory
	BulletType	m_shot1 = BULLET_PLAIN;
	BulletType	m_shot2 = BULLET_BIG;
	ItemType	m_item1 = ITEM_TEST;
	ItemType	m_item2 = ITEM_TEST;
	ItemType	m_item3 = ITEM_TEST;
	ItemType	m_item4 = ITEM_TEST;

private:
	void initialise(const Vector2& startPos);
};