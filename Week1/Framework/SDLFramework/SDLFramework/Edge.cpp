#include "Edge.h"

Edge::Edge(Vertex * v1, Vertex * v2)
{
	first = v1;
	second = v2;

	weight = Vertex::distance(first, second);
}

Vertex * Edge::getEnd(Vertex * start)
{
	if (first == start)
		return second;
	else
		return first;
}

bool Edge::isConnected(Vertex* v1, Vertex* v2)
{
	if ((v1 == first && v2 == second) || (v2 == first && v1 == second))
		return true;
	return false;
}