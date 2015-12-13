#pragma once
#include "AnimalState.h"

class HuntingState :
	public AnimalState
{
private:
	HuntingState() { name = "hunting"; }
public:
	~HuntingState();
	static HuntingState* cowHuntingInstance();
	static HuntingState* hareHuntingInstance();

	void enter(Animal* animal);
	Vertex* execute(Animal* animal);
	void exit(Animal* animal);
};

