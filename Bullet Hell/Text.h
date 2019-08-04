#pragma once
#include "GameObject.h"
#include "FontData.h"
#include "ResourceManager.h"

class Text : public Component
{
public:
	Text(FontType font, const char* text);
	~Text() {}

	void updateText(const char* text) { m_text = text; }
	/*Empty*/
	void update(GameObject* gameObject, float deltaTime) override {};
	/*Draws text at object's position.*/
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override;

private:
	std::shared_ptr<ResourceBase> m_font = nullptr;
	const char* m_text;
	Vector4 m_colour;
};