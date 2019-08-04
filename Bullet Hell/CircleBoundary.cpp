#include "CircleBoundary.h"

CircleBoundary::CircleBoundary(const Matrix3& transform, float radius)
{
	m_radius = radius;
	m_center = Vector2(transform.translation.x, transform.translation.y);
}

/*Returns the point on a circle closest to another point.*/
Vector2 CircleBoundary::closestPoint(const Vector2& point) const
{
	Vector2 toPoint = point - m_center;

	if (toPoint.magnitudeSqr() > m_radius * m_radius)
		toPoint = toPoint.normalised() * m_radius;

	return m_center + toPoint;
}

bool CircleBoundary::isInsideCircle(const Vector2& point) const
{
	Vector2 toPoint = point - m_center;
	return toPoint.magnitudeSqr() <= m_radius * m_radius;
}

bool CircleBoundary::overlaps(const CircleBoundary& other) const
{
	Vector2 difference = other.m_center - m_center;
	float radius = m_radius + other.m_radius;
	return difference.magnitudeSqr() < radius * radius;
}

bool CircleBoundary::overlaps(const BoxBoundary& box) const
{
	Vector2 difference = box.closestPoint(m_center) - m_center;
	return difference.dot(difference) <= m_radius * m_radius;
}

//bool overlaps(const CircleBoundary& circle) const
//{
//	Vector2 difference = closestPoint(circle.center()) - circle.center();
//	return difference.dot(difference) <= circle.radius() * circle.radius();
//}

void CircleBoundary::update(GameObject* gameObject, float deltaTime)
{
	m_center.x = gameObject->getLocalTransform().translation.x;
	m_center.y = gameObject->getLocalTransform().translation.y;
}

void CircleBoundary::draw(GameObject* gameObject, aie::Renderer2D* renderer)
{
	renderer->setRenderColour(0, 0, 255, 1);
	renderer->drawCircle(m_center.x, m_center.y, m_radius, 20);
	renderer->setRenderColour(1, 1, 1, 1);
}