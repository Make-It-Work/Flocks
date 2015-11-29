#pragma once
#include "AnimalState.h"
class WanderingState :
	public AnimalState
{
private:
	WanderingState();
public:
	~WanderingState();
	static WanderingState* cowWanderingInstance();
	static WanderingState* hareWanderingInstance();

	void enter(Animal* animal);
	Vertex* execute(Animal* animal);
	void exit(Animal* animal);
};

