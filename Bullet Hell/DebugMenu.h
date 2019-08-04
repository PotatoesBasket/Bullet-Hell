#pragma once
#include "Button.h"
#include <Input.h>

class DebugMenu : public GameObject
{
public:
	DebugMenu();
	~DebugMenu() {}

	enum Cursor
	{
		onStart,
		onExit
	};

	void checkInput();

	void onUpdate(float deltaTime) override;

private:
	aie::Input* m_input = nullptr;
	float m_inputDelay = 0.3f;
	float m_inputTimer = 0.0f;

	Cursor m_state = onStart;

	std::shared_ptr<Button> m_buttonStart;
	std::shared_ptr<Button> m_buttonExit;
};