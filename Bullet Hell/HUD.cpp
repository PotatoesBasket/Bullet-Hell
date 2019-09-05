#include "HUD.h"
#include "ScreenData.h"
#include "GameManager.h"

HUD::HUD()
{
	//create objects
	m_infoText = std::make_shared<Text>(FONT_DEBUG_BLK, ":D :D   you did it!   :D :D");
	m_timerText = std::make_shared<Text>(FONT_DEBUG_BLK, "");
	m_pointsText = std::make_shared<Text>(FONT_DEBUG_BLK, "");
	m_boss = std::make_shared<Text>(FONT_DEBUG_BLK, "boss");

	//attach children
	addChild(m_infoText.get());
	addChild(m_timerText.get());
	addChild(m_pointsText.get());
	addChild(m_boss.get());

	//init values
	m_infoText->move(SCR_HALFWIDTH - m_infoText->getHalfWidth(), 20);
	m_infoText->setActiveState(false);
	m_timerText->move(SCR_HALFWIDTH - 20, SCR_HEIGHT - 40);
	m_pointsText->move(10, SCR_HEIGHT - 40);
	m_boss->move(SCR_HALFWIDTH - m_boss->getHalfWidth(), 70);
}

void HUD::onUpdate(float deltaTime)
{
	GameManager& manager = GameManager::getInstance();

	if (manager.getBoss())
	{
		m_bossHealth = manager.getBoss()->getHealth();

		if (m_bossHealth > 0)
		{
			static float percent = m_barWidth / m_bossHealth;
			m_currentWidth = percent * m_bossHealth;
		}
		if (m_bossHealth <= 0)
		{
			m_boss->setActiveState(false);
			m_infoText->setActiveState(true);
			setTimerText("");
			setPointsText("");
		}
	}

	if (manager.getPlayer())
	{
		float playerHealth = manager.getPlayer()->getHealth();

		if (playerHealth <= 0)
		{
			setTimerText("");
			setPointsText("");
			setIntructionText("you ded  D:");
			m_infoText->setActiveState(true);
		}
	}
}

void HUD::onDraw(aie::Renderer2D* renderer)
{
	if (m_bossHealth > 0)
	{
		//draw boss health bar
		renderer->setRenderColour(1, 0, 0, 1);
		renderer->drawBox(m_barPos.x, m_barPos.y, m_currentWidth, m_barHeight);
		renderer->setRenderColour(1, 1, 1, 1);
	}
}

void HUD::setIntructionText(std::string text)
{
	m_infoText->updateText(text);
}

void HUD::setTimerText(std::string text)
{
	m_timerText->updateText(text);
}

void HUD::setPointsText(std::string text)
{
	m_pointsText->updateText(text);
}