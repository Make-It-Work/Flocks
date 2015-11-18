#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include <vector>
#include "DrawService.h"
#include <map>
#include <queue>
#include "VertexComparer.h"

Vertex::Vertex(int xc, int yc)
{
	x = xc;
	y = yc;
	edges = std::vector<Edge*>();
}
Vertex::~Vertex() {}

Edge* Vertex::connect(Vertex* target)
{
	Edge* e = new Edge(this, target);
	edges.push_back(e);
	return e;
}

int Vertex::estimate(Vertex* target)
{
	return distance(this, target);
}

int Vertex::distance(Vertex* v1, Vertex* v2)
{
	int x1 = v1->x;
	int y1 = v1->y;

	int x2 = v2->x;
	int y2 = v2->y;

	int distancex = (x2 - x1) * (x2 - x1);
	int distancey = (y2 - y1) * (y2 - y1);
	return (int)(sqrt(distancex + distancey) + 0.5);
}

void Vertex::print(FWApplication* app)
{
	print(app, std::vector<Edge*>(), std::vector<Vertex*>());
}

void Vertex::print(FWApplication* app, std::vector<Edge*> visitedEdges, std::vector<Vertex*> visitedVertices)
{
	if (!(std::find(visitedVertices.begin(), visitedVertices.end(), this) != visitedVertices.end()))
	{
		DrawService::DrawVert(app, this);
		visitedVertices.push_back(this);
	}
	for each (Edge* e in edges)
	{
		if (!(std::find(visitedEdges.begin(), visitedEdges.end(), e) != visitedEdges.end()))
		{
			DrawService::DrawEdge(app, e);
			visitedEdges.push_back(e);
		}
		if (!(std::find(visitedVertices.begin(), visitedVertices.end(), e->getEnd(this)) != visitedVertices.end()))
		{
			e->getEnd(this)->print(app, visitedEdges, visitedVertices);
		}
	}
}

bool Vertex::isLinked(Vertex* v)
{
	for each(Edge* e in edges)
	{
		if (e->isConnected(this, v))
			return true;
	}
	return false;
}

Vertex* Vertex::aMove(Vertex* target, Graph* g)
{
	Vertex* root = this;
	printf("start %i target %i \n", this->id, target->id);
	resetEfforts(g);
	
	std::priority_queue<Vertex*, std::vector<Vertex *>, VertexComparer> queue;
	std::vector<Vertex*> visited;
	std::map<Vertex*, Vertex*> prev;
	queue.push(root);
	root->minEffort = 0;
	std::string wayOut = "";
	if (root == target) {
		printf( "You are already at the exit!");
	}
	while (!queue.empty()) {
		root = queue.top();
		queue.pop();
		for (Edge* edge : root->edges) {
			if (edge->getEnd(root) != nullptr && !containsVertex(visited, edge->getEnd(root))) {
				if (edge->getEnd(root)->minEffort > root->minEffort + edge->getWeight()) {
					edge->getEnd(root)->minEffort = root->minEffort + edge->getWeight();
					prev.insert(std::make_pair(edge->getEnd(root), root));
				}
				queue.push(edge->getEnd(root));
			}
		}
		visited.push_back(root);
	}
	while (prev.find(target) != prev.end()) {
		printf("id %i", target->id);
		target = prev.at(target);
	}
	return target;
}

void Vertex::resetEfforts(Graph* graph) {
	for (Vertex* vertex : graph->getAllVertices()) {
		vertex->minEffort = INT_MAX;
	}
}
bool Vertex::containsVertex(std::vector<Vertex*> list, Vertex* v) {
	return find(list.begin(), list.end(), v) != list.end();
}