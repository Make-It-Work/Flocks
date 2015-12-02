#include "DrawService.h"
#include <string>

void DrawService::DrawVert(FWApplication* app, Vertex* v)
{
	app->DrawRect(v->x, v->y, 5, 5, true);
	app->DrawText(std::to_string(v->id), v->x, v->y - 10);
}

void DrawService::DrawVertWithEdges(FWApplication* app, Vertex* v)
{
	app->DrawRect(v->x, v->y, 5, 5, true);
	for each (Edge* e in v->edges)
	{
		DrawEdge(app, e);
	}
}

void DrawService::DrawEdge(FWApplication* app, Edge* e)
{
	int x = (e->first->x + e->second->x) / 2;
	int y = (e->first->y + e->second->y) / 2;
	std::string str = std::to_string(e->id) + "-" + std::to_string(e->getWeight());
	//app->DrawText(str, x, y - 10);
	app->DrawLine(e->first->x, e->first->y, e->second->x, e->second->y);
}

void DrawService::cow(FWApplication* app, Vertex* v)
{
	app->DrawTexture(app->LoadTexture("cow-2.png"), v->x, v->y, 48, 48);
}

void DrawService::hare(FWApplication* app, Vertex* v)
{
	app->DrawTexture(app->LoadTexture("rabbit-2.png"), v->x, v->y, 48, 48);
}

void DrawService::pill(FWApplication* app, Vertex* v)
{
	app->DrawTexture(app->LoadTexture("pill.png"), v->x, v->y, 48, 48);
}