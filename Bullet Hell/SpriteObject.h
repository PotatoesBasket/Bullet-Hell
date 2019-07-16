#pragma once
#include "GameObject.h"
#include <Texture.h>

class SpriteObject : public GameObject
{
public:
	SpriteObject() {};
	SpriteObject(const char* filename) { load(filename); }
	virtual ~SpriteObject() { delete m_texture; };

	bool load(const char* filename);

	virtual void onUpdate(float deltaTime) {}
	virtual void onDraw(aie::Renderer2D* renderer);

protected:
	aie::Texture* m_texture = nullptr;
};