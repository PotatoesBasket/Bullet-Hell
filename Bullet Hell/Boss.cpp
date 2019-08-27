#include "Boss.h"
#include "BulletData.h"
#include "GameManager.h"
#include <math.h>

Boss::Boss(Vector2 startPos, SpriteType sprite, BossType boss)
{
	GameManager::getInstance().setBoss(this);
	m_startPos = startPos;
	setPosition(startPos);
	m_health = boss.health;

	for (int i = 0; i != 12; ++i)
	{
		std::shared_ptr<BulletEmitter> emitter = std::make_shared<BulletEmitter>(BULLET_PLAIN, false);
		m_emitters.push_back(emitter);
		addChild(emitter.get());
	}

	//hurr durr wat is math
	float radius = BOSS_SHION.hurtRadius + 20;
	m_emitters[0]->setPosition(cosf(0.0f) * radius, sinf(0.0f) * radius);
	m_emitters[1]->setPosition(cosf(0.52f) * radius, sinf(0.52f) * radius);
	m_emitters[2]->setPosition(cosf(1.04f) * radius, sinf(1.04f) * radius);
	m_emitters[3]->setPosition(cosf(1.57f) * radius, sinf(1.57f) * radius);
	m_emitters[4]->setPosition(cosf(2.09f) * radius, sinf(2.09f) * radius);
	m_emitters[5]->setPosition(cosf(2.61f) * radius, sinf(2.61f) * radius);
	m_emitters[6]->setPosition(cosf(3.14f) * radius, sinf(3.14f) * radius);
	m_emitters[7]->setPosition(cosf(3.66f) * radius, sinf(3.66f) * radius);
	m_emitters[8]->setPosition(cosf(4.18f) * radius, sinf(4.18f) * radius);
	m_emitters[9]->setPosition(cosf(4.71f) * radius, sinf(4.71f) * radius);
	m_emitters[10]->setPosition(cosf(5.23f) * radius, sinf(5.23f) * radius);
	m_emitters[11]->setPosition(cosf(5.75f) * radius, sinf(5.75f) * radius);

	//Create and add components
	m_sprite = std::make_shared<Sprite>(sprite);
	addComponent(m_sprite);

	m_boundary = std::make_shared<BoxBoundary>(startPos, startPos + Vector2(boss.width, boss.height));
	addComponent(m_boundary);

	m_hurtBox = std::make_shared<CircleBoundary>(getGlobalTransform(), boss.hurtRadius);
	addComponent(m_hurtBox);
}

Boss::~Boss()
{
	GameManager::getInstance().removeBoss();
}

void Boss::characterUpdate(float deltaTime)
{
	m_moveTimer += deltaTime;
	m_actTimer += deltaTime;

	switch (m_moveState)
	{
	case wait:

		if (m_moveTimer >= 3.0f)
		{
			m_moveTimer = 0;
			m_moveState = backandforth;
		}
		break;

	case center:

		if (!m_returnToCenter)
		{
			m_direction = (m_startPos - getGlobalTransform().translation);
			m_direction.normalise();
			m_returnToCenter = true;
		}

		move(m_direction.x * deltaTime * 60, m_direction.y * deltaTime * 60);

		//once boss has reached destination, change state
		if (m_hurtBox->isInsideCircle(Vector2(m_startPos.x, m_startPos.y)))
		{
			m_returnToCenter = false;
			m_moveTimer = 0;
			m_moveState = wait;
		}

		break;

	case backandforth:

		m_shotTimer += deltaTime;

		if (m_currentEmitter == 12)
			m_currentEmitter = 0;

		if (m_shotTimer > 0.5f)
			m_canShoot = true;

		if (m_canShoot)
		{
			m_emitters[m_currentEmitter++]->fire();
			m_shotTimer = 0;
			m_canShoot = false;
		}

		m_yAngle += 0.006f;
		if (m_yAngle >= 3.14159 * 2)
			m_yAngle = 0;

		m_xAngle = m_yAngle * 3;

		move(cosf(m_xAngle) / 8, sinf(m_yAngle) * 0.80);

		if (m_moveTimer >= 5.0f)
		{
			m_moveTimer = 0;
			m_moveState = center;
		}
		break;
	}

	switch (m_actState)
	{
	case (none):
		break;
	case (shoot):
		break;
	}
}