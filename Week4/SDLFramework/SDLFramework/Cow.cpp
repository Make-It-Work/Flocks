#include "Cow.h"
#include "Vector2.h"
#include "BehaviourMachine.h"

Cow::Cow(Vector2 position, Hare* h)
	:MovingEntity(position, 8)
{
	m_pSteering = new SteeringBehaviors(this);
	prey = h;
}


Cow::~Cow()
{
}

void Cow::update(double time_elapsed) {
	Vector2 steeringForce = BehaviourMachine::Behave(this);
	Vector2 acceleration = steeringForce / m_dMass;
	m_vVelocity += acceleration * time_elapsed;
	m_vVelocity.truncate(m_dMaxSpeed); //Zorg ervoor dat hij niet harder gaat dan zijn max
	pos.x += m_vVelocity.x * time_elapsed;
	pos.y += m_vVelocity.y * time_elapsed;

	//update the heading if the vehicle has a velocity greater than a very small
	//value
	if (m_vVelocity.length() > 0.00000001)
	{
		m_vHeading = m_vVelocity.normalized();
		m_vSide = m_vHeading.perpendicular();
		//treat the screen as a toroid
	}
	WrapAround(pos.x, pos.y);

}