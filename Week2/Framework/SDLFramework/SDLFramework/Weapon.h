#pragma once
#include "Item.h"
#include <string>
#include "Vertex.h"

class Weapon
	: Item
{
public:
	Weapon(Vertex* v) {
		location = v;
	};
	~Weapon();
	const std::string texture = "gun-metal.png";
};