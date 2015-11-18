#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include <vector>
#include "DrawService.h"
#include <map>
#include <unordered_map>
#include <queue>
#include <concurrent_priority_queue.h>
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
	printf("shit %1 \n", id);
	target->edges.push_back(e);
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
	Vertex* start = this;
	std::priority_queue<Vertex*, std::vector<Vertex *>, VertexComparer> frontier;
	std::unordered_map<Vertex*, Vertex*>& came_from = std::unordered_map<Vertex*, Vertex*>();
	std::unordered_map<Vertex*, int>& cost_so_far = std::unordered_map<Vertex*, int>();
	frontier.push(start);

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		Vertex* current = frontier.top();
		frontier.pop();

		if (current == target) {
			break;
		}

		for (Edge* e : current->edges) {
			Vertex* next = e->getEnd(current);
			int new_cost = cost_so_far[current] + e->getWeight();
			if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				int priority = new_cost + next->estimate(target);
				frontier.push(next);
				came_from[next] = current;
			}
		}
	}
 	printf("");
	while (came_from.find(target) != came_from.end()) {
		target = came_from.at(target);
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