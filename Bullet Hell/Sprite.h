#pragma once
#include "GameObject.h"
#include "ResourceManager.h"
#include <Texture.h>

/*Supports animation of spritesheets. Place sprites horizontally on spritesheet.*/

class Sprite : public Component
{
public:
	Sprite(const char* filename) { load(filename); }
	Sprite(const char* filename, unsigned int columnCount, unsigned int rowCount, float animSpeed);
	~Sprite() {}

	void load(const char* filename);
	void updateUVRect(aie::Renderer2D* renderer);

	void update(GameObject* gameObject, float deltaTime) override { m_timer += deltaTime; };
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override;

protected:
	std::shared_ptr<ResourceBase> m_texture = nullptr;

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