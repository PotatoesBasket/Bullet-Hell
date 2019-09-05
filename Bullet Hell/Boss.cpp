#include "Boss.h"
#include "BulletData.h"
#include "ScreenData.h"
#include "GameManager.h"
#include <math.h>

Boss::Boss(Vector2 startPos, SpriteType sprite, BossType boss)
{
	GameManager::getInstance().setBoss(this); //tell game manager boss exists
	move(startPos); // place in world

	//create components
	m_sprite = std::make_shared<Sprite>(sprite);
	m_boundary = std::make_shared<BoxBoundary>(startPos, startPos + Vector2(boss.width, boss.height));
	m_hurtBox = std::make_shared<CircleBoundary>(getGlobalTransform(), boss.hurtRadius);
	m_centerTrigger = std::make_shared<CircleBoundary>(getGlobalTransform(), 1);

	//add components
	addComponent(m_sprite);
	addComponent(m_boundary);
	addComponent(m_hurtBox);
	addComponent(m_centerTrigger);

	//initialise emitters
	float radius = BOSS_SHION.hurtRadius + 20;
	for (unsigned int i = 0; i != 12; ++i)
	{
		std::shared_ptr<BulletEmitter> emitter =
			std::make_shared<BulletEmitter>(BULLET_BOSS1, false);
		m_emitters.push_back(emitter);
		addChild(emitter.get());

		float angle = 360 / 12 * i;
		float posOffset = 90;
		m_emitters[i]->move(
			cosf((angle - posOffset) * PI / 180) * radius,
			-sinf((angle - posOffset) * PI / 180) * radius);
		m_emitters[i]->rotate(-angle);
	}

	//init values
	m_health = boss.health;
	m_center = startPos;
}

Boss::~Boss()
{
	GameManager::getInstance().removeBoss();
}

void Boss::characterUpdate(float deltaTime)
{
	m_shotDelayTimer += deltaTime;

	linearActionPattern(deltaTime);

	switch (m_moveState)
	{
	case MoveWait: break;
	case MoveToCenter: moveToCenter(deltaTime); break;
	case MoveHelixUp: moveHelixUp(deltaTime); break;
	case MoveHelixDown: moveHelixDown(deltaTime); break;
	}

	switch (m_shootState)
	{
	case ShootNone: break;
	case ShootSpiralCW: shootSpiralCW(); break;
	case ShootSpiralCCW: shootSpiralCCW(); break;
	}
}

void Boss::setEmitterAngle(unsigned int emitterIdx, float degrees)
{
	if (emitterIdx >= 0 || emitterIdx < 12)
	{
		m_emitters[emitterIdx]->resetRotation();
		m_emitters[emitterIdx]->rotate(degrees);
	}
}

//MOVE FUNCTIONS

//returns boss to center position, switches movement to wait on arrival
void Boss::moveToCenter(float deltaTime)
{
	static bool gotDirection = false;
	static Vector3 direction;

	if (!gotDirection) //get direction once
	{
		direction = (m_center - getGlobalTransform().translation);
		direction.normalise();
		gotDirection = true;
	}

	move(direction.x * deltaTime * 150, direction.y * deltaTime * 150);

	//once boss has reached destination, change state directly to wait
	if (m_centerTrigger->isInsideCircle(Vector2(m_center.x, m_center.y)))
	{
		gotDirection = false;
		m_moveState = MoveWait;
	}
}

void Boss::moveHelixUp(float deltaTime)
{
	static bool init = false;
	static int fullCircles = 0;

	if (!init)
	{
		m_yAngle = PI * 0.5f; //initial angle
		init = true;
	}

	m_yAngle -= 0.002;
	m_xAngle = m_yAngle * 4;

	if (m_yAngle < 0)
	{
		m_yAngle = PI * 2;
		++fullCircles;
	}

	move(cosf(m_xAngle) * 200 * deltaTime, sinf(m_yAngle) * 200 * deltaTime);

	if (fullCircles == 2)
	{
		init = false;
		fullCircles = 0;
		m_moveState = MoveWait;
	}
}

void Boss::moveHelixDown(float deltaTime)
{
	static bool init = false;
	static int fullCircles = 0;

	if (!init)
	{
		m_yAngle = 3 * PI * 0.5f; //initial angle
		init = true;
	}

	m_yAngle += 0.002;
	m_xAngle = m_yAngle * 4;

	if (m_yAngle >= PI * 2)
	{
		m_yAngle = 0;
		++fullCircles;
	}

	move(cosf(m_xAngle) * 200 * deltaTime, sinf(m_yAngle) * 200 * deltaTime);

	if (fullCircles == 2)
	{
		init = false;
		fullCircles = 0;
		m_moveState = MoveWait;
	}
}

//SHOOT FUNCTIONS

//shoots from each emitter clockwise starting from 7oclock
void Boss::shootSpiralCW()
{
	static bool init = false;

	if (!init)
	{
		m_currentEmitter = 7;
		init = true;
	}

	if (m_currentEmitter == 12)
		m_currentEmitter = 0;

	if (m_shotDelayTimer > m_shotDelayFast)
		m_canShoot = true;

	if (m_canShoot)
	{
		m_emitters[m_currentEmitter++]->fire();
		m_shotDelayTimer = 0;
		m_canShoot = false;
	}

	if (m_moveState == MoveWait)
	{
		init = false;
	}
}

//shoots from each emitter counterclockwise starting from 11oclock
void Boss::shootSpiralCCW()
{
	static bool init = false;

	if (!init)
	{
		m_currentEmitter = 11;
		init = true;
	}

	if (m_currentEmitter == 0)
		m_currentEmitter = 12;

	if (m_shotDelayTimer > m_shotDelayFast)
		m_canShoot = true;

	if (m_canShoot)
	{
		m_emitters[--m_currentEmitter]->fire();
		m_shotDelayTimer = 0;
		m_canShoot = false;
	}

	if (m_moveState == MoveWait)
	{
		init = false;
	}
}

//ACTION PATTERN

//bad bad bad
void Boss::linearActionPattern(float deltaTime)
{
	static int actionNumber = 0;
	static float actTimer = 0;
	static bool initAction = false;

	actTimer += deltaTime;

	switch (actionNumber)
	{
	case 0:
		if (!initAction) //set states once
		{
			m_moveState = MoveHelixUp; //set move type
			m_shootState = ShootSpiralCW; //set shot type
			initAction = true; //initilisation done
		}
		if (m_moveState == MoveWait) //when action is done, state automatically changes to MoveWait
		{
			initAction = false; //reset init flag
			++actionNumber; //go to next action
		}
		break;

	case 1:
		if (!initAction)
		{
			m_moveState = MoveToCenter;
			m_shootState = ShootNone;
			initAction = true;
		}
		if (m_moveState == MoveWait)
		{
			initAction = false;
			++actionNumber;
		}
		break;

	case 2:
		if (!initAction)
		{
			m_moveState = MoveHelixDown;
			m_shootState = ShootSpiralCCW;
			initAction = true;
		}
		if (m_moveState == MoveWait)
		{
			initAction = false;
			++actionNumber;
		}
		break;

	case 3:
		if (!initAction)
		{
			m_moveState = MoveToCenter;
			m_shootState = ShootNone;
			initAction = true;
		}
		if (m_moveState == MoveWait)
		{
			initAction = false;
			++actionNumber;
		}
		break;

	//loop action list
	case 4:
		actTimer = 0;
		actionNumber = 0;
		break;
	}
}