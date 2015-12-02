#pragma once
#include <string>
#include "Vertex.h"

class Item
{
public:
	Item() {};
	Item(Vertex* v) { location = v; };
	~Item() {};
	std::string texture;
	Vertex* location;
};