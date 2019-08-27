#include "HUD.h"
#include "ScreenData.h"

HUD::HUD()
{
	m_infoText = std::make_shared<Text>(FONT_DEBUG_WHT, "info text was not entered");
	addChild(m_infoText.get());
	m_infoText->setPosition(0, 0);

	m_timerText = std::make_shared<Text>(FONT_DEBUG_WHT, "000:00");
	addChild(m_timerText.get());
	m_timerText->setPosition(SCR_HALFWIDTH - 20, SCR_HEIGHT - 20);

	m_pointsText = std::make_shared<Text>(FONT_DEBUG_WHT, "000000000000");
	addChild(m_pointsText.get());
	m_pointsText->setPosition(0, SCR_HEIGHT - 20);
}

void HUD::setIntructionText(const char* text)
{
	m_infoText->updateText(text);
}

void HUD::setTimerText(const char* text)
{
	m_timerText->updateText(text);
}

void HUD::setPointsText(const char* text)
{
	m_pointsText->updateText(text);
}