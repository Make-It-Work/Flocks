#pragma once
#include "Vector2.h"
#include "BaseGameEntity.h"
class MovingEntity : public BaseGameEntity
{
protected:

	Vector2 m_vVelocity = Vector2(0,0);
	//a normalized vector pointing in the direction the entity is heading.
	Vector2 m_vHeading = Vector2(0, 0);
	//a vector perpendicular to the heading vector
	Vector2 m_vSide = Vector2(0, 0);

	double m_dMass;
	//the maximum speed at which this entity may travel.
	double m_dMaxSpeed;
	//the maximum force this entity can produce to power itself
	//(think rockets and thrust)
	double m_dMaxForce;
	//the maximum rate (radians per second) at which this vehicle can rotate
	double m_dMaxTurnRate;

	void WrapAround(int x, int y);
public:
	MovingEntity(Vector2 vel, Vector2 head, Vector2 position);
	~MovingEntity();

	double getMaxSpeed() { return m_dMaxSpeed; };
	Vector2 getVelocity() { return m_vVelocity; };
};

