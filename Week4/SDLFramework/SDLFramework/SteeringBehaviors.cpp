#include "SteeringBehaviors.h"
#include "MovingEntity.h"
#include <algorithm>

SteeringBehaviors::SteeringBehaviors(MovingEntity* v)
{
	vehicle = v;
}


SteeringBehaviors::~SteeringBehaviors()
{
}

Vector2 SteeringBehaviors::calculate() {
	Vector2* vec = new Vector2(1,1);
	return *vec;
}

Vector2 Wander()
{
	return Vector2(0,0);
}

Vector2 SteeringBehaviors::Seek(Vector2 TargetPos)
{

	Vector2 DesiredVelocity = Vector2(TargetPos.x - vehicle->getPos().x, TargetPos.y - vehicle->getPos().y);
	DesiredVelocity.truncate(vehicle->getMaxSpeed());
	DesiredVelocity.x -= vehicle->getVelocity().x;
	DesiredVelocity.y -= vehicle->getVelocity().y;
	return DesiredVelocity;

}

Vector2 SteeringBehaviors::Flee(Vector2 TargetPos)
{
	if (Vector2::dist(vehicle->getPos(), TargetPos) > 100)
	{
		return Vector2(0, 0);
	}
	Vector2 DesiredVelocity = Vector2(vehicle->getPos().x - TargetPos.x, vehicle->getPos().y - TargetPos.y);
	DesiredVelocity.truncate(vehicle->getMaxSpeed());
	DesiredVelocity.x -= vehicle->getVelocity().x;
	DesiredVelocity.y -= vehicle->getVelocity().y;
	return DesiredVelocity;

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

Vector2 SteeringBehaviors::Pursuit(MovingEntity* evader)
{
		return Seek(evader->getPos());
}