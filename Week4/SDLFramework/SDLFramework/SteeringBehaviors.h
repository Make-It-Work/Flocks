#pragma once
#include "Vector2.h"
#include "MovingEntity.h"
enum Deceleration { slow = 3, normal = 2, fast = 1 };
class SteeringBehaviors
{
public:
	SteeringBehaviors(MovingEntity* v);
	~SteeringBehaviors();

	Vector2 calculate();

	Vector2 Wander();
	Vector2 Seek(Vector2 TargetPos);
	Vector2 Flee(Vector2 TargetPos);
	Vector2 Arrive(Vector2 TargetPos, Deceleration deceleration);
	Vector2 SteeringBehaviors::Pursuit(MovingEntity* evader);
private:
	MovingEntity* vehicle;
};

