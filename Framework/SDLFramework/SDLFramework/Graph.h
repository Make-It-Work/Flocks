#pragma once
#include "Vertex.h"

class Graph
{
public:
	Graph(int size);
	Vertex* first;
	std::vector<Vertex*> vertices;
};