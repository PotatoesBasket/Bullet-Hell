#include "Font.h"

Font::Font(FontType font, const char* text) : m_text(text)
{
	m_font = ResourceManager::getInstance().loadFont(font.filename, font.size);
	m_colour = font.colour;
}

void Font::draw(GameObject* gameObject, aie::Renderer2D* renderer)
{
	renderer->setRenderColour(m_colour.x, m_colour.y, m_colour.z, m_colour.w);
	renderer->drawText(m_font->as<aie::Font>(), m_text,
		gameObject->getGlobalTransform().translation.x,
		gameObject->getGlobalTransform().translation.y, 0);
	renderer->setRenderColour(1, 1, 1, 1);
}