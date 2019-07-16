#include "Player.h"
#include <Input.h>

Player::Player(const char* texture, int maxHealth)
{
	load(texture);
	setPosition(300, 350);
}

void Player::onUpdate(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		move(Vector2(1, 0) * deltaTime * speed);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		move(Vector2(-1, 0) * deltaTime * speed);
	}

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		move(Vector2(0, 1) * deltaTime * speed);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		move(Vector2(0, -1) * deltaTime * speed);
	}
}