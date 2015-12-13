#pragma once
#include <vector>
#include "FWApplication.h"
class Edge;

class Vertex
{
public:
	Vertex(int xc, int yc);
	~Vertex();

	int x;
	int y;
	int id;
	int minEffort = 9999;
	Edge* prev;

	Edge* connect(Vertex* target);
	void print(FWApplication* app);
	void print(FWApplication* app, std::vector<Edge*> visitedEdges, std::vector<Vertex*> visitedVertices);
	std::vector<Edge*> edges;
	int estimate(Vertex* target);

	bool isLinked(Vertex* v);

	static int distance(Vertex* v1, Vertex* v2);

};

