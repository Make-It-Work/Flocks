#pragma once
#include "Item.h"
#include <string>

class Pill
	: Item
{
public:
	Pill(Vertex* v) { location = v; };
	~Pill();
	const std::string texture = "pill.png";
};

