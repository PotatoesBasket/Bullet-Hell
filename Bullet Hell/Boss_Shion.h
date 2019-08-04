#pragma once
#include "Boss.h"

class Boss_Shion : public Boss
{
public:
	Boss_Shion(Vector2 startPos);
	~Boss_Shion() {}

	void onUpdate(float deltaTime) override;

private:
	const float m_animSpeed = 2.0f;
};