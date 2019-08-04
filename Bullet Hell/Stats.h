#pragma once
#include "GameObject.h"

class Stats : public Component
{
public:
	Stats();
	~Stats();

private:
	float m_health;
	float m_attack;
	float m_defence;
};