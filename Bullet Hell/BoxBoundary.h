#pragma once
#include "GameObject.h"

class BoxBoundary : public Component
{
public:
	enum Type
	{
		COLLIDER,
		TRIGGER
	};

	BoxBoundary(float width, float height, Type type) : m_width(width), m_height(height), m_type(type) {}
	~BoxBoundary() {}

private:
	float m_width;
	float m_height;
	Type m_type;
};