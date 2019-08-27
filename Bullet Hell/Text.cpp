#include "Text.h"

Text::Text(FontType font, const char* text) : m_text(text)
{
	m_font = ResourceManager::getInstance().loadFont(font.filename, font.size);
	m_colour = font.colour;
}

float Text::getHalfWidth()
{
	return m_font->as<aie::Font>()->getStringWidth(m_text) / 2;
}

float Text::getHalfHeight()
{
	return m_font->as<aie::Font>()->getStringHeight(m_text) / 2;
}

void Text::onDraw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(m_colour.x, m_colour.y, m_colour.z, m_colour.w);
	renderer->drawText(m_font->as<aie::Font>(), m_text,
		getGlobalTransform().translation.x, getGlobalTransform().translation.y, 0);
	renderer->setRenderColour(1, 1, 1, 1);
}