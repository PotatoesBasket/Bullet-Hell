#include "Player.h"
#include "Sprite.h"
#include <Input.h>

Player::Player(const char* texture, Vector2 startPos)
{
	std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(texture);
	addComponent(sprite);
	setPosition(startPos);
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