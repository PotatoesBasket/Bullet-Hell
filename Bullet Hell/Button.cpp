#include "Button.h"

Button::Button(TextButton button, const char* text)
{
	initText(button, text);
}

Button::Button(SpriteButton button)
{
	initSprite(button);
}

Button::Button(TextButton textStates, SpriteButton spriteStates, const char* text)
{
	initSprite(spriteStates);
	initText(textStates, text);
}

void Button::initText(TextButton button, const char* text)
{
	m_textOn = true;

	m_txtStandard = std::make_shared<Font>(button.standard, text);
	m_txtHover = std::make_shared<Font>(button.hover, text);
	m_txtPress = std::make_shared<Font>(button.press, text);

	addComponent(m_txtStandard);
	addComponent(m_txtHover);
	addComponent(m_txtPress);

	allComponentsOff();
}

void Button::initSprite(SpriteButton button)
{
	m_spriteOn = true;

	m_sprStandard = std::make_shared<Sprite>(button.standard);
	m_sprHover = std::make_shared<Sprite>(button.hover);
	m_sprPress = std::make_shared<Sprite>(button.press);

	addComponent(m_sprStandard);
	addComponent(m_sprHover);
	addComponent(m_sprPress);

	allComponentsOff();
}

void Button::setState(State state)
{
	m_state = state;

	//text components
	if (m_textOn == true)
	{
		switch (m_state)
		{
		case standard:
			m_txtStandard.get()->setActiveState(true);
			m_txtHover.get()->setActiveState(false);
			m_txtPress.get()->setActiveState(false);
			break;

		case hover:
			m_txtStandard.get()->setActiveState(false);
			m_txtHover.get()->setActiveState(true);
			m_txtPress.get()->setActiveState(false);
			break;

		case press:
			m_txtStandard.get()->setActiveState(false);
			m_txtHover.get()->setActiveState(false);
			m_txtPress.get()->setActiveState(true);
			break;
		}
	}

	//sprite components
	if (m_spriteOn == true)
	{
		switch (m_state)
		{
		case standard:
			m_sprStandard.get()->setActiveState(true);
			m_sprHover.get()->setActiveState(false);
			m_sprPress.get()->setActiveState(false);
			break;

		case hover:
			m_sprStandard.get()->setActiveState(false);
			m_sprHover.get()->setActiveState(true);
			m_sprPress.get()->setActiveState(false);
			break;

		case press:
			m_sprStandard.get()->setActiveState(false);
			m_sprHover.get()->setActiveState(false);
			m_sprPress.get()->setActiveState(true);
			break;
		}
	}
}