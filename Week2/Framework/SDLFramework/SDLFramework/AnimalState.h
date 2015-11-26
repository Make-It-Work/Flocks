#pragma once
class Animal;
class AnimalState
{
public:
	AnimalState();
	virtual ~AnimalState() {}

	virtual void enter(Animal* animal) = 0;
	virtual void execute(Animal* animal) = 0;
	virtual void exit(Animal* animal) = 0;

};

