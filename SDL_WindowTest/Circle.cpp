#include "Circle.hpp"

Circle::Circle(SDL_Renderer* renderer)
{
	Circle::renderer = renderer;
	pos = { .x = 250, .y = 100 };
	radius = 100;
}

void Circle::SetPosition(SDL_FPoint pos)
{
	Circle::pos = pos;
}

void Circle::SetRadius(float radius)
{
	Circle::radius = radius;
}

void Circle::Render()
{
	const int segments = 24;

	SDL_Vertex vert[segments * 3];
	for (int i = 0; i < segments; i++)
	{
		float t;
		int j = i * 3;

		vert[j].position.x = pos.x + 0;
		vert[j].position.y = pos.y + 0;

		t = (float)i / segments * 3.1416f * 2;
		vert[j + 1].position.x = pos.x + cos(t) * radius;
		vert[j + 1].position.y = pos.y + sin(t) * radius;

		t = (float)(i + 1) / segments * 3.1416f * 2;
		vert[j + 2].position.x = pos.x + cos(t) * radius;
		vert[j + 2].position.y = pos.y + sin(t) * radius;
	}

	SDL_RenderGeometry(renderer, NULL, vert, segments * 3, NULL, 0);
}
