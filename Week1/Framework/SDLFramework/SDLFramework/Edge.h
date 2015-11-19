#pragma once
#include "Vertex.h"

class Edge
{
public:
	Edge(Vertex* v1, Vertex* v2);
	~Edge();

	Vertex* getEnd(Vertex* start);
	bool isConnected(Vertex* v1, Vertex* v2);
	int getWeight() { return weight; };
	int id;
	Vertex* first;
	Vertex* second;
private:
	int weight;
};

