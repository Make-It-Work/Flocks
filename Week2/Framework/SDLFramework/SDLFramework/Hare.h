#pragma once
#include "Animal.h"
class Hare :
	public Animal
{
public:
	Hare(Vertex* start);
	~Hare();
	void makeAMove(Vertex* target);
	void update() {}
	void changeState(AnimalState* new_state);
};

