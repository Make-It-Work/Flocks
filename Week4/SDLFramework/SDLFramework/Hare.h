#pragma once
#include "MovingEntity.h"
#include "GameWorld.h"
#include "SteeringBehaviors.h"

class Hare : public MovingEntity
{
protected:
	GameWorld* gameWorld;
public:
	Hare(Vector2 position);
	~Hare();

	void update(double time_elapsed);
};

