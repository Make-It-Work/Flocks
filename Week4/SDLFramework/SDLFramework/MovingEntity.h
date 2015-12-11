#pragma once
#include "Vector2.h"
#include "BaseGameEntity.h"
class MovingEntity : public BaseGameEntity
{
protected:
	Vector2 m_vVelocity;
	//a normalized vector pointing in the direction the entity is heading.
	Vector2 m_vHeading;
	//a vector perpendicular to the heading vector
	Vector2 m_vSide;

	double m_dMass;
	//the maximum speed at which this entity may travel.
	double m_dMaxSpeed;
	//the maximum force this entity can produce to power itself
	//(think rockets and thrust)
	double m_dMaxForce;
	//the maximum rate (radians per second) at which this vehicle can rotate
	double m_dMaxTurnRate;
public:
	MovingEntity();
	~MovingEntity();
};

