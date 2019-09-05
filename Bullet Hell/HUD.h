#pragma once
#include "GameObject.h"
#include "Text.h"
#include "FontData.h"
#include "ScreenData.h"

class HUD : public GameObject
{
public:
	HUD();
	~HUD() {}

	void onUpdate(float deltaTime) override;
	void onDraw(aie::Renderer2D* renderer) override;

	void setIntructionText(std::string text);
	void setTimerText(std::string text);
	void setPointsText(std::string text);

private:
	std::shared_ptr<Text> m_infoText = nullptr;
	std::shared_ptr<Text> m_timerText = nullptr;
	std::shared_ptr<Text> m_pointsText = nullptr;
	std::shared_ptr<Text> m_boss = nullptr;

	//boss health bar
	const Vector2 m_barPos = { SCR_HALFWIDTH, 50 };
	const float m_barWidth = SCR_WIDTH - 200;
	const float m_barHeight = 5;
	float m_bossHealth = 0;
	float m_currentWidth = 0;
};