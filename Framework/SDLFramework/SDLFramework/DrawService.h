#pragma once
#include "Vertex.h"
#include "Edge.h"
#include "FWApplication.h"

class DrawService
{
public:
	static void DrawVert(FWApplication* app, Vertex* v);
	static void DrawVertWithEdges(FWApplication* app, Vertex* v);
	static void DrawEdge(FWApplication* app, Edge* e);
};