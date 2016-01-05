#pragma once
#include "Vector2.h"
#include "MovingEntity.h"
#include <vector>
enum Deceleration { slow = 3, normal = 2, fast = 1 };
class Cow;
class SteeringBehaviors
{
public:
	SteeringBehaviors(MovingEntity* v);
	~SteeringBehaviors();

	Vector2 calculate();

	Vector2 Wander();
	Vector2 Seek(Vector2 TargetPos);
	Vector2 Flee();
	Vector2 Arrive(Vector2 TargetPos, Deceleration deceleration);
	Vector2 SteeringBehaviors::Pursuit();
	Vector2 SteeringBehaviors::Separation(std::vector<Cow*> neighbors);
	Vector2 SteeringBehaviors::Alignment(std::vector<Cow*> neighbors);
	Vector2 SteeringBehaviors::Cohesion(std::vector<Cow*> neighbors);
private:
	MovingEntity* vehicle = nullptr;

	double travelTime(Vector2 TargetPos);
};

