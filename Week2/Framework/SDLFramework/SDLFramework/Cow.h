#pragma once
#include "Animal.h"
class Cow :
	public Animal
{
public:
	Cow(Vertex* start);
	~Cow();
	void makeAMove(Vertex* target);
	void update();
	void changeState(AnimalState* new_state);
	std::string getType() { return "Cow"; }
};

