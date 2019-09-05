#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <vector>
#include <memory>

/*
- Holds a set number of bullet objects of specified type
*/

class BulletPool : public Component
{
public:
	BulletPool(BulletType type, bool playerOwned);
	~BulletPool();

	void activateNext(GameObject* origin);

	void update(GameObject* gameObject, float deltaTime) override;
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override;

private:
	std::vector<Bullet*> m_bulletList;
	const unsigned int m_totalCount = 40;
};