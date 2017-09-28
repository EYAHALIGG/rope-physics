#pragma once

#include "Vec2f.h"

#include <Windows.h>

#define rgb(r,g,b) RGB(b,g,r)

class Circle;

class Graph
{
	static BITMAPINFO bmi;
	static int* pixels;
	static HWND hwnd;
	static HDC hdc;
public:
	static Vec2i size;
	Graph(Vec2i& _size);
	static void SetPixel(Vec2f& position, int color);
	static void FillRectangle(Vec2f& position, Vec2f& _size, int color);
	static void DrawLine(Vec2f& l1, Vec2f& l2, int color);
	static void DrawCircle(Circle* circle, int color);
	static void FillColor(int color);
	static void Update();
};