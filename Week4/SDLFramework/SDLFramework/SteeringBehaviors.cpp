#include "SteeringBehaviors.h"
#include "MovingEntity.h"
#include <algorithm>
#include <random>
#include <time.h>
#include "Cow.h"
#include <typeinfo>
#include "Vector2.h"
#include "BaseGameEntity.h"
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
	Cow* c = dynamic_cast<Cow*>(vehicle);
	if (c != NULL) {
		//Calculate forces and stuff
		Vector2 finalHeading = Vector2(0, 0);

		Vector2 per = Pursuit();
		
		finalHeading += per;
		finalHeading /= 1;

		vehicle->setHeading(finalHeading);

		return finalHeading;
	}

	return Wander();
}

Vector2 SteeringBehaviors::flock()
{
	Cow* c = dynamic_cast<Cow*>(vehicle);
	if (c != NULL) {
		Vector2 finalHeading = Vector2(0, 0);
		Vector2 sep = Separation(c->getNeighbours());
		Vector2 coh = Cohesion(c->getNeighbours());
		Vector2 ali = Alignment(c->getNeighbours());
		finalHeading += coh;
		finalHeading += sep;
		finalHeading += ali;
		finalHeading /= 3;
		return finalHeading;
	}
	return Wander();
}

Vector2 SteeringBehaviors::Wander()
{
	Vector2 vec = Vector2(10 - std::rand() % 20, 10 - std::rand() % 20);
	vec.truncate(vehicle->getMaxSpeed());
	vehicle->setBehaviour("Wander");
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
	Vector2 heading = Vector2(0, 0);
	
	if (Vector2::dist(vehicle->getPos(), TargetPos) > 150)
	{
		return Wander();
	}
	heading = Seek(TargetPos) * -1;
	vehicle->setBehaviour("Flee");
	return heading;
}

Vector2 SteeringBehaviors::Arrive(Vector2 TargetPos, Deceleration deceleration)
{
	vehicle->setBehaviour("Arrive");
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
	Vector2 heading = Vector2(0, 0);

	if ((Vector2::dist(vehicle->getPos(), evader->getPos()) < 150) || (Vector2::dist(vehicle->getPos(), projectedPoint) < 20))
	{
		return Seek(evader->getPos());
	}
	heading = Seek(projectedPoint);
	vehicle->setBehaviour("Pursuit");
	return heading;
}

Vector2 SteeringBehaviors::Separation(std::vector<Cow*> neighbors)
{
	Vector2 SteeringForce = Vector2(0, 0);
	for (int a = 0; a < neighbors.size(); ++a)
	{
		//make sure this agent isn't included in the calculations and that
		//the agent being examined is close enough.
		if ((neighbors[a] != vehicle))
		{
			Vector2 ToAgent = vehicle->getPos() - neighbors[a]->getPos();
			//scale the force inversely proportional to the agent's distance
			//from its neighbor.
			ToAgent.truncate(10);
			SteeringForce += ToAgent / ToAgent.length();
		}
	}
	return SteeringForce;
}

Vector2 SteeringBehaviors::Alignment(std::vector<Cow*> neighbors)
{
	//used to record the average heading of the neighbors
	Vector2 AverageHeading = Vector2(0, 0);
	//used to count the number of vehicles in the neighborhood
	int NeighborCount = 0;
	//iterate through all the tagged vehicles and sum their heading vectors
	for (int a = 0; a<neighbors.size(); ++a)
	{
		//make sure *this* agent isn't included in the calculations and that
		//the agent being examined is close enough
		if ((neighbors[a] != vehicle))
		{
			AverageHeading += neighbors[a]->getHeading();
			++NeighborCount;
		}
	}
	//if the neighborhood contained one or more vehicles, average their
	//heading vectors.
	if (NeighborCount > 0)
	{
		AverageHeading /= (double)NeighborCount;
	}
	vehicle->setHeading(AverageHeading);
	return vehicle ->getHeading();
}

Vector2 SteeringBehaviors::Cohesion(std::vector<Cow*> neighbors)
{
	//first find the center of mass of all the agents
	Vector2 CenterOfMass = Vector2(0, 0);
	Vector2 SteeringForce = Vector2(0,0);
	int NeighborCount = 0;
	//iterate through the neighbors and sum up all the position vectors
	for (int a = 0; a<neighbors.size(); ++a)
	{
		//make sure *this* agent isn't included in the calculations and that
		//the agent being examined is a neighbor
		if ((neighbors[a] != vehicle) && neighbors[a]->getPos().dist(neighbors[a]->getPos(), vehicle->getPos()) > 100)
		{
			CenterOfMass += neighbors[a]->getPos();
			++NeighborCount;
		}
	}
	if (NeighborCount > 0)
	{
		//the center of mass is the average of the sum of positions
		CenterOfMass /= (double)NeighborCount;
		//now seek toward that position
		SteeringForce = Seek(CenterOfMass);
	}
	return SteeringForce;
}


double SteeringBehaviors::travelTime(Vector2 TargetPos)
{
	return Vector2::dist(vehicle->getPos(), TargetPos);
}