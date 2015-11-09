#include "Vertex.h"

#pragma once
class Edge
{
public:
	Edge(Vertex v1, Vertex v2);
	~Edge();

	Vertex getEnd(Vertex start);
	int getWeight();
private:
	int weight;
	Vertex first;
	Vertex second;+
};

