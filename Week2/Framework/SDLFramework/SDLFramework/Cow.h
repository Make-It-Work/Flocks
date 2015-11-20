#pragma once
#include "Animal.h"
class Cow :
	public Animal
{
public:
	Cow(Vertex* start);
	~Cow();
	void makeAMove(Vertex* target);
};

