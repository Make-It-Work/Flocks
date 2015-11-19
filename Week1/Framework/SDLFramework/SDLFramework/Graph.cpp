#include "Graph.h"
#include "Edge.h"

Graph::Graph(int size)
{
	int id = 0;
	int nVertices = size;

	for (int i = 0; i < nVertices; i++)
	{
		Vertex* v = new Vertex(rand() % 750 + 1, rand() % 600 + 1);
		v->id = id++;
		vertices.push_back(v);
	}

	for each(Vertex* v in vertices)
	{
		int nConnections = 0;
		int nConnections_goal = rand() % 2 + 1;
		while (nConnections < nConnections_goal)
		{
			int index = rand() % vertices.size();
			Vertex* targ = vertices[index];
			if (!v->isLinked(targ))
			{
				Edge* e = v->connect(targ);
				e->id = id++;
				nConnections++;
			}
	
		}
	}

	first = vertices.front();

}