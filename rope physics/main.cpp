#include <iostream>
#include <ctime>

#include "Vec2f.h"
#include "Rope.h"
#include "Graph.h"
#include "Joint.h"
#include "Circle.h"

Vec2f mousePosition()
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(GetConsoleWindow(), &p);
	return Vec2f(p.x, p.y);
}

int main()
{
	Graph(Vec2i(500));
	float deltaTime = 0;
	float elapsedTime = 0;
	Rope* rope = new Rope(Vec2f(100, 20), Vec2f(1, 0) * 8, 50, 50);
	rope->joints[rope->freq/2]->isAnchor = true;
	rope->circles.push_back(new Circle(Vec2f(350, 150), 85));
	Circle *mouseCircle = new Circle();
	mouseCircle->radius = 30;
	rope->circles.push_back(mouseCircle);
	while (true)
	{
		int startTime = clock();
		mouseCircle->position = mousePosition();
		int iter = deltaTime / 0.002f + 1;
		float dt = deltaTime;
		if (iter) { dt = deltaTime / iter; }
		for (int i = 0; i < iter; i++) { rope->Update(dt); }
		Graph::Update();
		deltaTime = float(clock() - startTime) / CLOCKS_PER_SEC;
		elapsedTime += deltaTime;
	}
	return 0;
}