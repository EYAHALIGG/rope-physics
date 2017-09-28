#pragma once

#include "Vec2f.h"

class Joint
{
public:
	Vec2f position, velocity;
	bool isAnchor = false;
	Joint(Vec2f& _position) : position(_position) {}
	void AddForce(Vec2f& force);
	void Update(float dt);
};