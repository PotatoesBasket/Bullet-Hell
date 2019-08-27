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

	m_txtStandard = std::make_shared<Text>(button.standard, text);
	m_txtHover = std::make_shared<Text>(button.hover, text);
	m_txtPress = std::make_shared<Text>(button.press, text);

	addChild(m_txtStandard.get());
	addChild(m_txtHover.get());
	addChild(m_txtPress.get());

	m_txtStandard->setActiveState(false);
	m_txtHover->setActiveState(false);
	m_txtPress->setActiveState(false);
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
			m_txtStandard->setActiveState(true);
			m_txtHover->setActiveState(false);
			m_txtPress->setActiveState(false);
			break;

		case hover:
			m_txtStandard->setActiveState(false);
			m_txtHover->setActiveState(true);
			m_txtPress->setActiveState(false);
			break;

		case press:
			m_txtStandard->setActiveState(false);
			m_txtHover->setActiveState(false);
			m_txtPress->setActiveState(true);
			break;
		}
	}

	//sprite components
	if (m_spriteOn == true)
	{
		switch (m_state)
		{
		case standard:
			m_sprStandard->setActiveState(true);
			m_sprHover->setActiveState(false);
			m_sprPress->setActiveState(false);
			break;

		case hover:
			m_sprStandard->setActiveState(false);
			m_sprHover->setActiveState(true);
			m_sprPress->setActiveState(false);
			break;

		case press:
			m_sprStandard->setActiveState(false);
			m_sprHover->setActiveState(false);
			m_sprPress->setActiveState(true);
			break;
		}
	}
}