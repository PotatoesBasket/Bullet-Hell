#include "Character.h"
#include "ScreenData.h"
#include "GameManager.h"

void Character::takeDamage(float damage)
{
	m_health -= (int)damage;

	if (m_health > 0)
	{
		//play damage animation
	}
	else
	{
		//death animation
		setActiveState(false);
	}
}

void Character::checkLevelBoundary()
{
	if (m_localTransform.translation.x < 0 + m_boundary->width() * 0.5f)
		m_localTransform.translation.x = 0 + m_boundary->width() * 0.5f;
	if (m_localTransform.translation.x > SCR_WIDTH - m_boundary->width() * 0.5f)
		m_localTransform.translation.x = SCR_WIDTH - m_boundary->width() * 0.5f;
	if (m_localTransform.translation.y < 0 + m_boundary->height() * 0.5f)
		m_localTransform.translation.y = 0 + m_boundary->height() * 0.5f;
	if (m_localTransform.translation.y > SCR_HEIGHT - m_boundary->height() * 0.5f)
		m_localTransform.translation.y = SCR_HEIGHT - m_boundary->height() * 0.5f;
}

void Character::onUpdate(float deltaTime)
{
	checkLevelBoundary();
	characterUpdate(deltaTime);
}