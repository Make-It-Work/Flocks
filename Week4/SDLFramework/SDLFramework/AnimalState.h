#pragma once
#include <string>
class Animal;
class Vertex;
class AnimalState
{
protected:
	std::string name;
public:
	AnimalState();
	virtual ~AnimalState() {}

	virtual void enter(Animal* animal) = 0;
	virtual Vertex* execute(Animal* animal) = 0;
	virtual void exit(Animal* animal) = 0;

	std::string getName() { return name; }

};

