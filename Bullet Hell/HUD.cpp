#include "HUD.h"

HUD::HUD()
{
	m_infoText = std::make_shared<Font>(FONT_DEBUG_WHT, "");
	addComponent(m_infoText);

	m_timerText = std::make_shared<Font>(FONT_DEBUG_WHT, "00:00");
	addComponent(m_timerText);
}

void HUD::setIntruction(const char* text)
{
	m_infoText.get()->updateText(text);
}

void HUD::setTimer(const char* text)
{
	m_timerText.get()->updateText(text);
}