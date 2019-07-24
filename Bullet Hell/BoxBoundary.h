#pragma once
#include "GameObject.h"
#include "MathLibrary.h"
#include <Renderer2D.h>

class BoxBoundary : public Component
{
public:
	BoxBoundary(const Vector2& min, const Vector2& max) : m_min(min), m_max(max),
		m_width(max.x - min.x), m_height(max.y - min.y) {}
	~BoxBoundary() {}

	Vector2 center() const;
	float width() const { return m_width; }
	float height() const { return m_height; }
	//Vector2 closestPoint(const Vector2& point) const;

	bool isInsideBox(const Vector2& point) const;
	bool overlaps(const BoxBoundary& other) const;
	//bool overlaps(const CircleBoundary& circle) const;

	void update(GameObject* gameObject, float deltaTime) override; //update position
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override; //debug only

	float min(float a, float b) { return a < b ? a : b; }
	float max(float a, float b) { return a > b ? a : b; }
	Vector2 min(const Vector2& a, const Vector2& b) { return { min(a.x, b.x), min(a.y, b.y) }; }
	Vector2 max(const Vector2& a, const Vector2& b) { return { max(a.x, b.x), max(a.y, b.y) }; }

private:
	Vector2 m_min;
	Vector2 m_max;
	float m_width;
	float m_height;
};