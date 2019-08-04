#pragma once
#include "Player.h"

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
		debug_menu,
		debug_weapontest,
		splash,
		title,
		levelSelect,
		game
	};

	GameState getGameState() { return m_state; }
	void setGameState(GameState state) { m_state = state; }

private:
	Player* m_player = nullptr;
	GameState m_state = game;

	unsigned int m_points = 0;
};