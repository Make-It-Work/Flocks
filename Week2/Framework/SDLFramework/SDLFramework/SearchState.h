#pragma once
#pragma once
#include "AnimalState.h"

class SearchingState :
	public AnimalState
{
private:
	SearchingState();
public:
	~SearchingState();
	static SearchingState* cowSearchingInstance();
	static SearchingState* hareSearchingInstance();

	void enter(Animal* animal);
	Vertex* execute(Animal* animal);
	void exit(Animal* animal);
};

