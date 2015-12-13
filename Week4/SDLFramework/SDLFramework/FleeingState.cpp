#include "FleeingState.h"
#include "Animal.h"
#include "Edge.h"
#include "SearchingState.h"

FleeingState::~FleeingState()
{
}

FleeingState* FleeingState::hareFleeingInstance()
{
	static FleeingState cowInstance;
	return &cowInstance;
}

void FleeingState::enter(Animal* animal)
{
	printf("%s entering Fleeing state \n", animal->getType().c_str());
	animal->setBored(0);
}

Vertex* FleeingState::execute(Animal* animal)
{
	printf("%s executing Fleeing state \n", animal->getType().c_str());
	std::vector<Edge*> edges = animal->getPosition()->edges;
	//Pick an edge
	Vertex* preyPosition = animal->prey->getPosition();
	Vertex* furthest = edges.front()->getEnd(animal->getPosition());
	for (Edge* e : edges)
	{
		Vertex* v = e->getEnd(animal->getPosition());
		if (
			(Vertex::distance(v, preyPosition) > Vertex::distance(furthest, preyPosition) && v->edges.size() > 1 ) ||
			(furthest->edges.size() == 1 && v->edges.size() > 1)
			)
		{
			furthest = v;
		}
	}
	animal->setPosition(furthest);

	return furthest;
}

void FleeingState::exit(Animal* animal)
{
	printf("%s exiting Fleeing state \n", animal->getType().c_str());
}
