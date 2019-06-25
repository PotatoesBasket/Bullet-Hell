#pragma once
#include "Point2D.h"
#include "Texture.h"
#include <Renderer2D.h>
#include <string>

class GameObject
{
public:
	GameObject(Point2D position, char* filename) :
		m_position{ position },
		m_texture{ new aie::Texture(filename) } {}

	virtual ~GameObject() {}

	virtual void update(float deltaTime) = 0;
	virtual void draw(aie::Renderer2D* renderer) = 0;
	
	Point2D getPos() { return m_position; }

protected:
	Point2D m_position;
	aie::Texture* m_texture;
};