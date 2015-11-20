#include "Hare.h"

Hare::Hare(Vertex* start)
{
	position = start;
}


Hare::~Hare()
{
}

void Hare::makeAMove(Vertex* target)
{
	position = target;
}
