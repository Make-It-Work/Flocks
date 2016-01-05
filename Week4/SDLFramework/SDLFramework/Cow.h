#pragma once
#include "MovingEntity.h"
#include "GameWorld.h"
#include "SteeringBehaviors.h"
#include "Hare.h"
#include <string>

class Cow : public MovingEntity
{
protected:
	std::vector<Cow*> neighbours;
	double neighbourRadius = 150;
public:
	Cow(Vector2 position, Hare* h);
	~Cow();
	void update(double time_elapsed);
	void tagNeighbours(GameWorld* gameWorld);
	std::vector<Cow*> getNeighbours() { return neighbours; }

	Vector2 projection = Vector2(0, 0);
};

