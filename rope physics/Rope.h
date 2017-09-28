#pragma once

#include "Vec2f.h"

#include <vector>

class Joint;
class Circle;

class Rope
{
public:
	int freq;
	float distance, k;
	Joint* head, **joints;
	std::vector<Circle*> circles;
	Rope(Vec2f& start, Vec2f& dir, int _freq, float _k);
	void Update(float dt);
};