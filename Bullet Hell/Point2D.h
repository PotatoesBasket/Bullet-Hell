#pragma once

class Point2D
{
public:
	float x;
	float y;

	Point2D& operator+=(const Point2D& other)
	{
		Point2D* p = this;
		p->x = x + other.x;
		p->y = y + other.y;
		return *p;
	}

	Point2D& operator*(const float& n)
	{
		Point2D* p = this;
		p->x = x * n;
		p->y = y * n;
		return *p;
	}
};