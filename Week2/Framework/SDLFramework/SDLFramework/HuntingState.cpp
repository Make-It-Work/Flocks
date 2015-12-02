#include "HuntingState.h"
#include "Animal.h"
#include "Edge.h"
#include "item.h"

HuntingState::HuntingState()
{
}


HuntingState::~HuntingState()
{
}

HuntingState* HuntingState::cowHuntingInstance()
{
	static HuntingState cowInstance;
	return &cowInstance;
}

void HuntingState::enter(Animal* animal)
{
	printf("%s entering Hunting state \n", animal->getType().c_str());
}

Vertex* HuntingState::execute(Animal* animal)
{
	animal->makeAMove(animal->prey->getPosition());
	return nullptr;

}

void HuntingState::exit(Animal* animal)
{
	printf("%s exiting Hunting state \n", animal->getType().c_str());
}
