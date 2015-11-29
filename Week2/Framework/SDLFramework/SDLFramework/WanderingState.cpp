#include "WanderingState.h"
#include "Animal.h"
#include "Edge.h"

WanderingState::WanderingState()
{
}


WanderingState::~WanderingState()
{
}

WanderingState* WanderingState::cowWanderingInstance()
{
	static WanderingState cowInstance;
	return &cowInstance;
}

WanderingState* WanderingState::hareWanderingInstance()
{
	static WanderingState cowInstance;
	return &cowInstance;
}

void WanderingState::enter(Animal* animal)
{
	printf("%i entering wandering state", animal->getType());
}

Vertex* WanderingState::execute(Animal* animal)
{
	printf("%i executing wandering state", animal->getType());
	std::vector<Edge*> edges = animal->getPosition()->edges;
	//Pick an edge
	int randIndex = rand() % edges.size();
	return edges[randIndex]->getEnd(animal->getPosition());

}

void WanderingState::exit(Animal* animal)
{
	printf("%i exiting wandering state", animal->getType());
}
