#include "DebugMenu.h"
#include "ScreenData.h"
#include "ButtonData.h"

DebugMenu::DebugMenu()
{
	m_input = aie::Input::getInstance();

	//initialise start button
	m_buttonStart = std::make_shared<Button>(BUTTON_TEXTTEST, "start");
	addChild(m_buttonStart.get());
	m_buttonStart->setPosition(SCR_HALFWIDTH, SCR_HEIGHT - 30);
	m_buttonStart->setState(Button::hover);

	//initialise exit button
	m_buttonExit = std::make_shared<Button>(BUTTON_TEXTTEST, "exit");
	addChild(m_buttonExit.get());
	m_buttonExit->setPosition(SCR_HALFWIDTH, SCR_HEIGHT - 90);
	m_buttonExit->setState(Button::standard);
}

void DebugMenu::checkInput()
{
	if (m_input->isKeyDown(aie::INPUT_KEY_S) || m_input->isKeyDown(aie::INPUT_KEY_W) ||
		m_input->isKeyDown(aie::INPUT_KEY_A) || m_input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_inputTimer = 0;

		switch (m_state)
		{
		case onStart:
			m_buttonStart->setState(Button::standard);
			m_buttonExit->setState(Button::hover);
			m_state = onExit;
			break;
		case onExit:
			m_buttonStart->setState(Button::hover);
			m_buttonExit->setState(Button::standard);
			m_state = onStart;
			break;
		}
	}

	if (m_input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		m_inputTimer = 0;

		switch (m_state)
		{
		case onStart:
			m_buttonStart->setState(Button::press);
			m_manager.setGameState(GameManager::game);
			break;
		case onExit:
			m_buttonExit->setState(Button::press);
			break;
		}
	}
}

void DebugMenu::onUpdate(float deltaTime)
{
	m_inputTimer += deltaTime;

	if (m_inputTimer > m_inputDelay)
		checkInput();
}