#pragma once
#include "AnimalState.h"

class HuntingState :
	public AnimalState
{
private:
	HuntingState();
public:
	~HuntingState();
	static HuntingState* cowHuntingInstance();

	void enter(Animal* animal);
	Vertex* execute(Animal* animal);
	void exit(Animal* animal);
};

