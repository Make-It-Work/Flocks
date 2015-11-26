#pragma once
#include "Vertex.h"
#include "Pill.h"
#include "AnimalState.h"
class Animal
{
protected:
	Vertex* position = nullptr;
	//Pill* pill = nullptr;
	int bored = 0; // > 5 ga chasen
	AnimalState* current_state = nullptr;
public:
	Animal() {}
	Animal(Vertex* start);
	~Animal();

	virtual void update() = 0;
	virtual void changeState(AnimalState* new_state) = 0;

	virtual void makeAMove(Vertex* target) = 0;
	Vertex* getPosition() { return position; }
	void setPosition(Vertex* target) { position = target; }
};

