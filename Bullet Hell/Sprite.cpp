#include "Sprite.h"
#include "ResourceManager.h"

Sprite::Sprite(const char* filename, unsigned int frameCount, float animSpeed) :
	m_frameCount(frameCount), m_animSpeed(animSpeed)
{
	load(filename);
	m_sheetWidth = m_texture->as<aie::Texture>()->getWidth();
	m_sheetHeight = m_texture->as<aie::Texture>()->getHeight();
	m_spriteWidth = m_texture->as<aie::Texture>()->getWidth() / frameCount;
}

void Sprite::load(const char* filename)
{
	m_texture = ResourceManager::getInstance().get(ResourceManager::TEXTURE, filename);
}

void Sprite::updateUVRect(aie::Renderer2D* renderer)
{
	float percent = 1.0f / m_frameCount;
	renderer->setUVRect(percent * m_currentFrame, 1, percent, 1);

	if (m_timer > m_animSpeed)
	{
		renderer->setUVRect(percent * m_currentFrame, 1, percent, 1);
		++m_currentFrame;

		if (m_currentFrame > m_frameCount)
			m_currentFrame = 1;

		m_timer = 0;
	}
}

void Sprite::draw(GameObject* gameObject, aie::Renderer2D* renderer)
{
	updateUVRect(renderer);
	renderer->drawSpriteTransformed3x3(m_texture->as<aie::Texture>(), gameObject->getGlobalTransformFloat(), m_spriteWidth, m_sheetHeight);
	renderer->setUVRect(1, 1, 1, 1);
}