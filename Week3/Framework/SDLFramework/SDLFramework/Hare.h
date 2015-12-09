#pragma once
#include "Animal.h"
class Hare :
	public Animal
{
public:
	Hare(Vertex* start);
	~Hare();
	void update();
	void changeState(AnimalState* new_state);

	std::string getType() { return "Hare"; }

	int fleeSuccess = 1;
	int gunSuccess = 1;
	int pillSuccess = 1;
	int counter = 0;
	std::string countHelper = "none";
};

