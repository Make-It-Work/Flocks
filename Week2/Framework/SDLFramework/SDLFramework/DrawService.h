#pragma once
#include "Vertex.h"
#include "Edge.h"
#include "FWApplication.h"
#include <unordered_map>

class DrawService
{
public:
	static void DrawVert(FWApplication* app, Vertex* v);
	static void DrawVertWithEdges(FWApplication* app, Vertex* v);
	static void DrawEdge(FWApplication* app, Edge* e);

	static void cow(FWApplication* app, Vertex* v);
	static void hare(FWApplication* app, Vertex* v);
	static void pill(FWApplication* app, Vertex* v);
	static void weapon(FWApplication* app, Vertex* v);
};