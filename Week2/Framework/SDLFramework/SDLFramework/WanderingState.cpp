#include "WanderingState.h"
#include "Animal.h"
#include "Edge.h"
#include "SearchingState.h"

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
	printf("%s entering wandering state \n", animal->getType().c_str());
	animal->setBored(0);
}

Vertex* WanderingState::execute(Animal* animal)
{
	printf("%s executing wandering state \n", animal->getType().c_str());
	std::vector<Edge*> edges = animal->getPosition()->edges;
	//Pick an edge
	int randIndex = rand() % edges.size();
	Vertex* goal = edges[randIndex]->getEnd(animal->getPosition());
	animal->setPosition(goal);


	if (animal->getBored() > 5) {
		animal->changeState(SearchingState::cowSearchingInstance());
	}

	return goal;
}

void WanderingState::exit(Animal* animal)
{
	printf("%s exiting wandering state \n", animal->getType().c_str());
}
