#pragma once

#include "Vec2f.h"

class Circle
{
public:
	Vec2f position;
	float radius;
	Circle() {}
	Circle(Vec2f& _position, float _radius) : position(_position), radius(_radius) {}
};