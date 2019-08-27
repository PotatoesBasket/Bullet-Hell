#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteData.h"

class Decoration : public GameObject
{
public:
	Decoration(SpriteType sprite, Vector2 position)
	{
		m_sprite = std::make_shared<Sprite>(sprite);
		addComponent(m_sprite);

		setPosition(position);
	}

	~Decoration() {}

private:
	std::shared_ptr<Sprite> m_sprite;
};