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
	Hare();
	~Hare();

	void update(double time_elapsed);
};

