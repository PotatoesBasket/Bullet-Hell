#pragma once
#include "GameObject.h"
#include "ResourceManager.h"
#include "SpriteData.h"
#include <Texture.h>

class Sprite : public Component
{
public:
	Sprite(SpriteType sprite);
	~Sprite() {}

	//call to change sprite currently being displayed
	void changeSprite(SpriteType sprite);

private:
	void updateUVRect(aie::Renderer2D* renderer);

	void update(GameObject* gameObject, float deltaTime) override { m_timer += deltaTime; };
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override;

protected:
	std::shared_ptr<ResourceBase> m_texture = nullptr;

	//animation info
	float m_animSpeed = 1;
	float m_timer = 0;
	unsigned int m_currentCol = 0;
	unsigned int m_currentRow = 0;

	//spritesheet info
	unsigned int m_columnCount = 1;
	unsigned int m_rowCount = 1;

	unsigned int m_sheetWidth = 0;
	unsigned int m_sheetHeight = 0;

	unsigned int m_spriteWidth = 0;
	unsigned int m_spriteHeight = 0;
};