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
		debug_weapontest,
		splash,
		title,
		levelSelect,
		game
	};

	GameState getGameState() { return m_state; }
	void setGameState(GameState state) { m_state = state; }

	bool checkPlaying() { return m_runApp; }
	void exitGame() { m_runApp = false; }

	void setPlayer(Player* player) { m_player = player; }
	void removePlayer() { m_player = nullptr; }
	Player* getPlayer() { return m_player; }

	void setBoss(Boss* boss) { m_boss = boss; }
	void removeBoss() { m_boss = nullptr; }
	Boss* getBoss() { return m_boss; }

	unsigned int getPoints() { return m_points; }
	void addPoints(int points) { m_points += points; }
	void removePoints(int points) { if ((m_points -= points) < 0) points = 0; }

	//void saveData();
	//void loadData();

private:
	GameState m_state = titleScreen;
	bool m_runApp = true;

	Player* m_player = nullptr;
	Boss* m_boss = nullptr;

	unsigned int m_points = 0;
};