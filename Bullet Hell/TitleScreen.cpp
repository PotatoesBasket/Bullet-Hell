#include "TitleScreen.h"
#include "ScreenData.h"
#include "ButtonData.h"

TitleScreen::TitleScreen()
{
	m_input = aie::Input::getInstance();

	//create objects
	m_title = std::make_shared<Text>(FONT_TITLE, "bad programmer art");
	m_title2 = std::make_shared<Text>(FONT_TITLE2, "ADVENTURE");
	m_subtitle = std::make_shared<Text>(FONT_SUBTITLE, "(deadlines and aesthetic don't mix)");
	m_buttonStart = std::make_shared<Button>(BUTTON_TITLESCR, "begin");
	m_buttonExit = std::make_shared<Button>(BUTTON_TITLESCR, "quit");
	m_player = std::make_shared<Decoration>(SPRITE_PLAYER_TUTORIAL);

	//add objects to scene's children (render order first to last)
	addChild(m_title.get());
	addChild(m_title2.get());
	addChild(m_subtitle.get());
	addChild(m_buttonStart.get());
	addChild(m_buttonExit.get());
	addChild(m_player.get());

	//initialise values
	m_title->move(
		SCR_HALFWIDTH - m_title->getHalfWidth(), //centered
		SCR_HEIGHT - 220); //anchored to top

	m_title2->move(
		SCR_HALFWIDTH - m_title2->getHalfWidth(),
		SCR_HEIGHT - 320);

	m_subtitle->move(
		SCR_HALFWIDTH - m_subtitle->getHalfWidth(),
		SCR_HEIGHT - 360);

	m_buttonStart->move(
		SCR_HALFWIDTH - m_buttonStart->getTextHalfWidth(),
		SCR_HALFHEIGHT - 90);

	m_buttonExit->move(
		SCR_HALFWIDTH - m_buttonExit->getTextHalfWidth(),
		SCR_HALFHEIGHT - 130);

	m_player->move(500, 200);

	m_buttonStart->setState(Button::hover);
	m_buttonExit->setState(Button::standard);
}

void TitleScreen::checkInput()
{
	//choose button
	if (m_input->isKeyDown(aie::INPUT_KEY_S) || m_input->isKeyDown(aie::INPUT_KEY_W) ||
		m_input->isKeyDown(aie::INPUT_KEY_A) || m_input->isKeyDown(aie::INPUT_KEY_D) ||
		m_input->isKeyDown(aie::INPUT_KEY_UP) || m_input->isKeyDown(aie::INPUT_KEY_DOWN) ||
		m_input->isKeyDown(aie::INPUT_KEY_RIGHT) || m_input->isKeyDown(aie::INPUT_KEY_LEFT))
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

	//select button
	if (m_input->isKeyDown(aie::INPUT_KEY_SPACE) || m_input->isKeyDown(aie::INPUT_KEY_ENTER))
	{
		m_inputTimer = 0;

		switch (m_state)
		{
		case onStart:
			m_buttonStart->setState(Button::press);
			m_manager.setGameState(GameManager::level1);
			break;
		case onExit:
			m_buttonExit->setState(Button::press);
			m_manager.exitGame();
			break;
		}
	}
}

void TitleScreen::onUpdate(float deltaTime)
{
	//input delay
	m_inputTimer += deltaTime;

	if (m_inputTimer > m_inputDelay)
		checkInput();
}