#include "Hare.h"

Hare::Hare()
{
}


Hare::~Hare()
{
}

void Hare::update(double time_elapsed) {
	Vector2 steeringForce = m_pSteering->calculate();
	Vector2 acceleration = steeringForce / m_dMass;
	m_vVelocity += acceleration * time_elapsed;
	//m_vVelocity.truncate(m_dMaxSpeed); Zorg ervoor dat hij niet harder gaat dan zijn max
	xPos += m_vVelocity.x * time_elapsed;
	yPos += m_vVelocity.y * time_elapsed;

}