#pragma once
#include "AnimalState.h"
class FleeingState :
	public AnimalState
{
private:
	FleeingState() { name = "Fleeing"; }
public:
	~FleeingState();
	static FleeingState* hareFleeingInstance();

	void enter(Animal* animal);
	Vertex* execute(Animal* animal);
	void exit(Animal* animal);
};

