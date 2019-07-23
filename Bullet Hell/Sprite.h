#pragma once
#include "GameObject.h"
#include "ResourceManager.h"
#include <Texture.h>

class Sprite : public Component
{
public:
	Sprite(const char* filename) { load(filename); }
	~Sprite() {};

	void load(const char* filename);

	void update(GameObject* gameObject, float deltaTime) override {}
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override;

protected:
	std::shared_ptr<ResourceBase> m_texture = nullptr;
};