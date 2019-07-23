#include "Enemy.h"
#include "Sprite.h"

Enemy::Enemy(const char* texture, Vector2 startPos)
{
	std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(texture);
	addComponent(sprite);
	setPosition(startPos);
}