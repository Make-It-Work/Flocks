#pragma once
class Animal;
class Vertex;
class AnimalState
{
public:
	AnimalState();
	virtual ~AnimalState() {}

	virtual void enter(Animal* animal) = 0;
	virtual Vertex* execute(Animal* animal) = 0;
	virtual void exit(Animal* animal) = 0;

};

