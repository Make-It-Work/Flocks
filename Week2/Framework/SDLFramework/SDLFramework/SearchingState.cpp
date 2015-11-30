#include "SearchingState.h"
#include "Animal.h"
#include "Edge.h"

SearchingState::SearchingState()
{
}


SearchingState::~SearchingState()
{
}

SearchingState* SearchingState::cowSearchingInstance()
{
	static SearchingState cowInstance;
	return &cowInstance;
}

SearchingState* SearchingState::hareSearchingInstance()
{
	static SearchingState cowInstance;
	return &cowInstance;
}

void SearchingState::enter(Animal* animal)
{
	printf("%i entering Searching state", animal->getType());
}

Vertex* SearchingState::execute(Animal* animal)
{
	printf("%i executing Searching state", animal->getType());
	std::vector<Edge*> edges = animal->getPosition()->edges;
	//Pick an edge
	int randIndex = rand() % edges.size();
	return edges[randIndex]->getEnd(animal->getPosition());

}

void SearchingState::exit(Animal* animal)
{
	printf("%i exiting Searching state", animal->getType());
}
