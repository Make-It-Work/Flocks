#pragma once
#include "Item.h"
#include <string>

class Vertex;
class Pill
	: public Item
{
public:
	Pill(Vertex* v) { location = v; };
	~Pill() {};
	const std::string texture = "pill.png";
};

