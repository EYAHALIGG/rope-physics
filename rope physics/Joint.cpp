#include "Joint.h"
#include "Rope.h"
#include "Graph.h"

#include <Windows.h>

void Joint::AddForce(Vec2f & force)
{
	velocity += force;
}

void Joint::Update(float dt)
{
	Graph::FillRectangle(position, Vec2f(4, 4), -1);
	if (isAnchor) { return; }
	AddForce(Vec2f(0, 9.8 / 10));
	AddForce(velocity*-0.009);
	position += velocity*dt;
}
