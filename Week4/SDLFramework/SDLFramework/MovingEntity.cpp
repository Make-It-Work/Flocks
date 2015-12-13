#include "MovingEntity.h"



MovingEntity::MovingEntity(Vector2 vel, Vector2 head, Vector2 position)
	: BaseGameEntity(position)
{
	m_vVelocity = vel;
	m_vHeading = head;
}


MovingEntity::~MovingEntity()
{
}

void MovingEntity::WrapAround(int x, int y)
{
	if (x > 800)
		x -= 800;
	if (y > 600)
		y -= 600;
}