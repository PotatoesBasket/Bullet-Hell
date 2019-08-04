#pragma once
#include "GameObject.h"
#include "Font.h"
#include "FontData.h"

class HUD : public GameObject
{
public:
	HUD();
	~HUD() {}

	void setIntruction(const char* text);
	void setTimer(const char* text);

private:
	std::shared_ptr<Font> m_infoText = nullptr;
	std::shared_ptr<Font> m_timerText = nullptr;

	char* m_infoContent = "invalid information text";
	char* m_timerContent = "00:00";
};