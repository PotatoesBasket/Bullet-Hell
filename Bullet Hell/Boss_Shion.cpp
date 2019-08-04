#include "Boss_Shion.h"
#include "BossData.h"

Boss_Shion::Boss_Shion(Vector2 startPos) :
	Boss(startPos, SPRITE_BOSS_1, BOSS_SHION) {}

void Boss_Shion::onUpdate(float deltaTime)
{
	m_actTimer += deltaTime;
}