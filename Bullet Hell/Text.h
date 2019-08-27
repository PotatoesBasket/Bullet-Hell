#pragma once
#include "GameObject.h"
#include "FontData.h"
#include "ResourceManager.h"

class Text : public GameObject
{
public:
	Text(FontType font, const char* text);
	~Text() {}

	/*Changes text displayed.*/
	void updateText(const char* text) { m_text = text; }

	float getHalfWidth(); //for centering things properly
	float getHalfHeight();

	/*Draws text at object's position.*/
	void onDraw(aie::Renderer2D* renderer) override;

private:
	std::shared_ptr<ResourceBase> m_font = nullptr;
	const char* m_text = "a";
	Vector4 m_colour = Vector4(1, 1, 1, 1);
};