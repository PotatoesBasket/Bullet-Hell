#include "Boss.h"
#include "BulletData.h"
#include <time.h>

Boss::Boss(Vector2 startPos, SpriteType sprite, BossType boss)
{
	setPosition(startPos);

	for (int i = 0; i != 12; ++i)
	{
		std::shared_ptr<BulletEmitter> emitter = std::make_shared<BulletEmitter>(BULLET_PLAIN);
		m_emitters.push_back(emitter);
		addChild(emitter.get());
	}

	//Create and add components
	m_sprite = std::make_shared<Sprite>(sprite);
	addComponent(m_sprite);

	m_boundary = std::make_shared<BoxBoundary>(startPos, startPos + Vector2(boss.width, boss.height));
	addComponent(m_boundary);

	m_hurtbox = std::make_shared<CircleBoundary>(startPos, boss.hurtRadius);
	addComponent(m_hurtbox);
}