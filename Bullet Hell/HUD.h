#pragma once
#include "GameObject.h"
#include "Text.h"
#include "FontData.h"

class HUD : public GameObject
{
public:
	HUD();
	~HUD() {}

private:
	std::shared_ptr<Text> m_info = nullptr;
};