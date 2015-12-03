#pragma once
#include <string>
#include "Vertex.h"
class Animal;
class Item
{
public:
	Item() {};
	Item(Vertex* v) { location = v; };
	~Item() {};
	std::string texture;
	bool hasOwner() { return owner != nullptr; }
	Vertex* getLocation() { return location; }
	void setLocation(Vertex* v) { location = v; }
protected:
	Vertex* location;
	Animal* owner;
};