#include "SteeringBehaviors.h"
#include "MovingEntity.h"
#include <algorithm>
#include <random>
#include <time.h>
#include "Cow.h"
#include <typeinfo>

SteeringBehaviors::SteeringBehaviors(MovingEntity* v)
{
	srand(time(NULL));
	vehicle = v;
}


SteeringBehaviors::~SteeringBehaviors()
{
}

Vector2 SteeringBehaviors::calculate() 
{
	return Wander();
}

Vector2 SteeringBehaviors::Wander()
{
	Vector2 vec = Vector2(10 - std::rand() % 20, 10 - std::rand() % 20);
	vec.truncate(vehicle->getMaxSpeed());
	return vec;
}

Vector2 SteeringBehaviors::Seek(Vector2 TargetPos)
{

	Vector2 DesiredVelocity = Vector2(TargetPos.x - vehicle->getPos().x, TargetPos.y - vehicle->getPos().y);
	DesiredVelocity.truncate(vehicle->getMaxSpeed());
	DesiredVelocity.x -= vehicle->getVelocity().x;
	DesiredVelocity.y -= vehicle->getVelocity().y;
	return DesiredVelocity;

}

Vector2 SteeringBehaviors::Flee()
{
	Hare* h = (Hare*)vehicle;
	Vector2 TargetPos = h->prey->getPos();
	
	if (Vector2::dist(vehicle->getPos(), TargetPos) > 100)
	{
		return Wander();
	}
	return Seek(TargetPos) * -1;

}

Vector2 SteeringBehaviors::Arrive(Vector2 TargetPos, Deceleration deceleration)
{
	Vector2 ToTarget = TargetPos - vehicle->getPos();
	double dist = Vector2::dist(vehicle->getPos(), TargetPos);
	if (dist > 0)
	{
		//because Deceleration is enumerated as an int, this value is required
		//to provide fine tweaking of the deceleration.
		const double DecelerationTweaker = 0.3;

		//calculate the speed required to reach the target given the desired
		//deceleration
		double speed = dist / ((double)deceleration * DecelerationTweaker);

		//make sure the velocity does not exceed the max
		speed = std::min(speed, vehicle->getMaxSpeed());

		//from here proceed just like Seek except we don't need to normalize
		//the ToTarget vector because we have already gone to the trouble
		//of calculating its length: dist.
		Vector2 DesiredVelocity = ToTarget * speed / dist;

		return (DesiredVelocity - vehicle->getVelocity());
	}
}

Vector2 SteeringBehaviors::Pursuit()
{
	Cow* c = (Cow*)vehicle;
	MovingEntity* evader = c->prey;
	Vector2 projectedPoint = evader->getHeading();
	projectedPoint.truncate(travelTime(evader->getPos()));
	projectedPoint += evader->getPos();
	projectedPoint.wrap();
	c->projection = projectedPoint;

	if ((Vector2::dist(vehicle->getPos(), evader->getPos()) < 150) || (Vector2::dist(vehicle->getPos(), projectedPoint) < 20))
	{
		return Seek(evader->getPos());
	}
	return Seek(projectedPoint);
}

double SteeringBehaviors::travelTime(Vector2 TargetPos)
{
	return Vector2::dist(vehicle->getPos(), TargetPos);
}