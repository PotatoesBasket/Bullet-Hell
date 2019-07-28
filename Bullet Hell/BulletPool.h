#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <vector>
#include <memory>

class BulletPool : public Component
{
public:
	BulletPool(const char* filename, unsigned int maxCount, float lifetime, float speed);
	~BulletPool();

	void activateNext(GameObject* origin);

	void update(GameObject* gameObject, float deltaTime) override;
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override;

private:
	std::vector<Bullet*> m_bulletList;

	unsigned int m_activeCount = 0;
	unsigned int m_totalCount = 0;
};