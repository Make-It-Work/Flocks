#include <vector>

#pragma once
class Vertex
{
public:
	Vertex();
	~Vertex();

	int x;
	int y;

	void Connect(Vertex target);
	std::vector<Edge> edges;
};

