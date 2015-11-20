#pragma once
#include "Animal.h"
class Hare :
	public Animal
{
public:
	Hare(Vertex* start);
	~Hare();
	void makeAMove(Vertex* target);
};

