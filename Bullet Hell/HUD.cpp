#include "HUD.h"

HUD::HUD()
{
	m_info = std::make_shared<Text>(FONT_DEBUG_WHT, "WASD - move, Space - shoot, ESC - quit");
	addComponent(m_info);
}