#pragma once
#include "MovingEntity.h"
#include "GameWorld.h"
#include "SteeringBehaviors.h"
#include "Hare.h"

class Cow : public MovingEntity
{
protected:
	GameWorld* gameWorld;
public:
	Cow(Vector2 position, Hare* h);
	~Cow();
	void update(double time_elapsed);

	Vector2 projection = Vector2(0, 0);
};

