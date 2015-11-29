#include "Cow.h"
#include <unordered_map>
#include <queue>
#include "Edge.h"
#include "WanderingState.h"

Cow::Cow(Vertex* start)
{
	position = start;
	current_state = WanderingState::cowWanderingInstance();
}


Cow::~Cow()
{
}

void Cow::update() {
	bored++;
	if (current_state != nullptr) {
		position = current_state->execute(this);
	}
}

void Cow::makeAMove(Vertex* target) {
	Vertex* start = position;
	std::unordered_map<Vertex*, Vertex*> came_from;
	std::unordered_map<Vertex*, int> cost_so_far;
	Vertex*Location;
	std::priority_queue<Vertex*> frontier;
	frontier.push(start);

	//came_from[start] = start;
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
	printf("moving from %i to %i \n", position->id, target->id);
	printf("====path======== \n");
	Vertex* ret = nullptr;
	Vertex* next = target;
	bool found = false;
	while (!found)
	{
		if (came_from.at(next) != position)
		{
			next = came_from.at(next);
		}
		else
		{
			ret = next;
			found = true;
			break;
		}
	}
	for (auto entry : came_from)
	{
		printf("%i from %i \n", entry.first->id, entry.second->id);
		//printf("%i goes to %i \n", entry.second->id, entry.first->id);
		if (entry.second == position)
		{
			//printf("stepping to %i \n", entry.first->id);
			//next = entry.first;
		}
	}
	printf("Stepping to %i \n", ret->id);
	position = ret;
}

void Cow::changeState(AnimalState* new_state) {
	current_state->exit(this);
	current_state = new_state;
	new_state->enter(this);
}