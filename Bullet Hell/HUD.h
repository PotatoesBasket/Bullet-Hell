#pragma once
#include "GameObject.h"
#include "Text.h"
#include "FontData.h"

class HUD : public GameObject
{
public:
	HUD();
	~HUD() {}

	void setIntructionText(const char* text);
	void setTimerText(const char* text);
	void setPointsText(const char* text);

private:
	std::shared_ptr<Text> m_infoText = nullptr;
	std::shared_ptr<Text> m_timerText = nullptr;
	std::shared_ptr<Text> m_pointsText = nullptr;
};