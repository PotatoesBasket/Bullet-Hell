#include "TitleScreen.h"
#include "ScreenData.h"
#include "ButtonData.h"

TitleScreen::TitleScreen()
{
	m_input = aie::Input::getInstance();

	//tiled background
	int idx = 0;
	for (int x = 0; x < 5; ++x)
		for (int y = 0; y < 3; ++y)
		{
			m_bgtiles[idx] = std::make_shared<Decoration>(SPRITE_TITLETILE, Vector2(1024 * x, 1024 * y));
			addChild(m_bgtiles[idx].get());
			++idx;
		}

	//create objects
	m_title = std::make_shared<Text>(FONT_TITLE_WHT, "aestivation");
	m_buttonStart = std::make_shared<Button>(BUTTON_TITLESCR, "begin");
	m_buttonExit = std::make_shared<Button>(BUTTON_TITLESCR, "quit");
	m_flower = std::make_shared<Decoration>(SPRITE_YELLOWFLOWER, Vector2(SCR_WIDTH * 0.25, SCR_HALFHEIGHT * 0.5));

	//add objects to scene's children (render order first to last)
	addChild(m_flower.get());
	addChild(m_title.get());
	addChild(m_buttonStart.get());
	addChild(m_buttonExit.get());

	//initialise values
	m_title->setPosition(SCR_HALFWIDTH - m_title->getHalfWidth(), SCR_HALFHEIGHT + 50);
	m_buttonStart->setPosition(SCR_HALFWIDTH - m_buttonStart->getTextHalfWidth(), SCR_HALFHEIGHT - 90);
	m_buttonStart->setState(Button::hover);
	m_buttonExit->setPosition(SCR_HALFWIDTH - m_buttonExit->getTextHalfWidth(), SCR_HALFHEIGHT - 120);
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
			m_manager.setGameState(GameManager::debug_weapontest);
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

	m_flower->rotate(0.05f * deltaTime);

	if (m_inputTimer > m_inputDelay)
		checkInput();
}