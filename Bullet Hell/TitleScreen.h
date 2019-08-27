#pragma once
#include "Button.h"
#include "GameManager.h"
#include "Decoration.h"
#include <Input.h>

class TitleScreen : public GameObject
{
public:
	TitleScreen();
	~TitleScreen() {}

	enum Cursor
	{
		onStart,
		onExit
	};

	void checkInput();

	void onUpdate(float deltaTime);

private:
	aie::Input* m_input = nullptr;
	GameManager& m_manager = GameManager::getInstance();

	float m_inputDelay = 0.3f;
	float m_inputTimer = 0.0f;

	Cursor m_state = onStart;

	std::shared_ptr<Text> m_title;
	std::shared_ptr<Button> m_buttonStart;
	std::shared_ptr<Button> m_buttonExit;

	std::shared_ptr<Decoration> m_flower;
	float m_flowerTimer = 0;

	std::shared_ptr<Decoration> m_bgtiles[15];
};