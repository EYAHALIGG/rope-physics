#include "Rope.h"
#include "Joint.h"
#include "Graph.h"
#include "Circle.h"

Rope::Rope(Vec2f & start, Vec2f & dir, int _freq, float _k)
{
	freq = _freq;
	k = _k;
	distance = dir.Length();
	joints = new Joint*[freq];
	for (int i = 0; i < freq; i++)
		joints[i] = new Joint(start + dir * i);
	head = *joints;
	head->isAnchor = true;
}

void Rope::Update(float dt)
{
	for (int k = 0; k < circles.size(); k++)
	{
		Graph::DrawCircle(circles[k], -1);
		Vec2f ab;
		for (int i = 0; i < freq; i++)
			if ((ab = joints[i]->position - circles[k]->position).Dot() <= (circles[k]->radius)*(circles[k]->radius))
				joints[i]->AddForce(ab.Normalise()*(circles[k]->radius - ab.Length()) * 2);
	}
	for (int i = 1; i < freq; i++)
	{
		Vec2f v = joints[i]->position - joints[i - 1]->position;
		float x = v.Length() - distance;
		Vec2f n = v.Normalise();
		Vec2f f = n*(x*k);
		if (joints[i]->isAnchor || joints[i - 1]->isAnchor) { f *= 2; }
		joints[i]->AddForce(-f);
		joints[i - 1]->AddForce(f);
		Graph::DrawLine(joints[i]->position, joints[i - 1]->position, -1);
	}
	for (int i = 0; i < freq; i++) { joints[i]->Update(dt); }
}
