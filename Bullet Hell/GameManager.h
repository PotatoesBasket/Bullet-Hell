#pragma once
#include "Player.h"
#include "Boss.h"
#include <time.h>

class GameManager
{
private:
	GameManager() {}
	GameManager(const GameManager&) {}
	GameManager& operator=(const GameManager&) {}

public:
	~GameManager() {}

	static GameManager& getInstance()
	{
		static GameManager instance;
		return instance;
	}

	enum GameState
	{
		titleScreen,
		level1,
	};

	GameState getGameState() { return m_state; }
	void setGameState(GameState state) { m_state = state; }

	bool checkPlaying() { return m_runApp; }
	void exitGame() { m_runApp = false; }

	int getTimer() { return (int)m_timer; }
	void addTime(float value) { m_timer += value; }
	void resetTimer() { m_timer = 0; }

	long getPoints() { return m_points; }
	void addPoints(int points);
	void removePoints(int points);

	void setPlayer(Player* player) { m_player = player; }
	void removePlayer() { m_player = nullptr; }
	Player* getPlayer() { return m_player; }

	void setBoss(Boss* boss) { m_boss = boss; }
	void removeBoss() { m_boss = nullptr; }
	Boss* getBoss() { return m_boss; }

private:
	bool m_runApp = true;
	float m_timer = 0;
	long m_points = 0;

	GameState m_state = titleScreen;

	Player* m_player = nullptr;
	Boss* m_boss = nullptr;
};