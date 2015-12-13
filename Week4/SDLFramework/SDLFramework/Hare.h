#pragma once
#include "MovingEntity.h"
#include "GameWorld.h"
#include "SteeringBehaviors.h"

class Hare : public MovingEntity
{
protected:
	GameWorld* gameWorld;
	SteeringBehaviors* m_pSteering;
public:
	Hare(Vector2 vel, Vector2 head, Vector2 position);
	~Hare();

	void update(double time_elapsed);
};

