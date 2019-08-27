#pragma once
#include "GameObject.h"
#include "MathLibrary.h"
#include "BoxBoundary.h"
#include <Renderer2D.h>

class CircleBoundary : public Component
{
public:
	CircleBoundary(const Vector2& point, float radius) : m_center(point), m_radius(radius) {}
	CircleBoundary(const Matrix3& transform, float radius);
	~CircleBoundary() {}

	Vector2 center() const { return m_center; }
	float radius() const { return m_radius; }
	Vector2 closestPoint(const Vector2& point) const;

	bool isInsideCircle(const Vector2& point) const;
	bool overlaps(std::shared_ptr<CircleBoundary> other) const;
	bool overlaps(std::shared_ptr<BoxBoundary> box) const;

	void earlyUpdatePosition(GameObject* gameObject); //for that one time with the bullets
	void update(GameObject* gameObject, float deltaTime) override; //update position
	void draw(GameObject* gameObject, aie::Renderer2D* renderer) override; //debug only

private:
	Vector2 m_center;
	float m_radius;
};