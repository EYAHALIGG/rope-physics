#include "Graph.h"
#include "Circle.h"

BITMAPINFO Graph::bmi;
int* Graph::pixels;
HWND Graph::hwnd;
HDC Graph::hdc;
Vec2i Graph::size;

Graph::Graph(Vec2i & _size)
{
	size = _size;
	pixels = new int[size.x*size.y];
	bmi = { sizeof(BITMAPINFOHEADER),size.x,-size.y,1,32 };
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
}

void Graph::SetPixel(Vec2f & position, int color)
{
	int x = position.x;
	int y = position.y;
	if ((x >= 0) && (y >= 0) && (x < size.x) && (y < size.y)) { pixels[x + y*size.x] = color; }
}

void Graph::FillRectangle(Vec2f & position, Vec2f & _size, int color)
{
	Vec2f half = _size / 2;
	for (int x = 0; x < _size.x; x++)
		for (int y = 0; y < _size.y; y++)
			SetPixel(position - half + Vec2f(x, y), color);
}

void Graph::DrawLine(Vec2f & l1, Vec2f & l2, int color)
{
	int x1 = l1.x;
	int y1 = l1.y;
	int x2 = l2.x;
	int y2 = l2.y;

	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2, e2;
	for (;;) {
		SetPixel(Vec2f(x1, y1), color);
		if (x1 == x2 && y1 == y2) break;
		e2 = err;
		if (e2 > -dx) { err -= dy; x1 += sx; }
		if (e2 < dy) { err += dx; y1 += sy; }
	}
}

void Graph::DrawCircle(Circle * circle, int color)
{
	int x = circle->position.x;
	int y = circle->position.y;
	int xx = circle->radius;

	int yy = 0;
	int err = 0;

	while (xx >= yy)
	{
		SetPixel(Vec2f(x + xx, y + yy), color);
		SetPixel(Vec2f(x + yy, y + xx), color);
		SetPixel(Vec2f(x - yy, y + xx), color);
		SetPixel(Vec2f(x - xx, y + yy), color);
		SetPixel(Vec2f(x - xx, y - yy), color);
		SetPixel(Vec2f(x - yy, y - xx), color);
		SetPixel(Vec2f(x + yy, y - xx), color);
		SetPixel(Vec2f(x + xx, y - yy), color);
		yy++;
		err += 1 + 2 * yy;
		if (2 * (err - xx) + 1 > 0)
		{
			xx--;
			err += 1 - 2 * xx;
		}
	}
}

void Graph::FillColor(int color)
{
	int area = size.x*size.y;
	for (int i = 0; i < area; i++) { pixels[i] = color; }
}

void Graph::Update()
{
	StretchDIBits(hdc, 0, 0, size.x, size.y, 0, 0, size.x, size.y, pixels, &bmi, 0, SRCCOPY);
	SwapBuffers(hdc);
	FillColor(rgb(45, 45, 45));
}
