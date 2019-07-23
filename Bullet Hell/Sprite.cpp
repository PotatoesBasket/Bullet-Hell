#include "Sprite.h"
#include "ResourceManager.h"

void Sprite::load(const char* filename)
{
	m_texture = ResourceManager::getInstance().get(ResourceManager::TEXTURE, filename);
}

void Sprite::draw(GameObject* gameObject, aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(m_texture->as<aie::Texture>(), gameObject->getGlobalTransformFloat());
}