#pragma once
#include "Vertex.h"
class Animal
{
protected:
	Vertex* position = nullptr;
public:
	Animal() {}
	Animal(Vertex* start);
	~Animal();
	virtual void makeAMove(Vertex* target) = 0;
	Vertex* getPosition() { return position; }
	void setPosition(Vertex* target) { position = target; }
};

