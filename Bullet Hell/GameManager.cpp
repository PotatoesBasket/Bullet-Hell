#include "GameManager.h"

void GameManager::addPoints(int points)
{
	if (m_points + points < LONG_MAX)
		m_points += points;
}

void GameManager::removePoints(int points)
{
	if (m_points - points > 0)
		m_points -= points;
}