#include "SearchingState.h"
#include "Animal.h"
#include "Edge.h"
#include "item.h"

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
	printf("%s entering Searching state \n", animal->getType().c_str());
}

Vertex* SearchingState::execute(Animal* animal)
{
	animal->makeAMove(animal->goal->getLocation());
	return nullptr;

}

void SearchingState::exit(Animal* animal)
{
	printf("%s exiting Searching state \n", animal->getType().c_str());
}
