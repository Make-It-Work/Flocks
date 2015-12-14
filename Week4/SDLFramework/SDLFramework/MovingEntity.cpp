#include "MovingEntity.h"



MovingEntity::MovingEntity(Vector2 position, double maxSpeed)
	: BaseGameEntity(position)
{
	m_dMaxSpeed = maxSpeed;
}


MovingEntity::~MovingEntity()
{
}

void MovingEntity::WrapAround(int x, int y)
{
	pos.x = (x > 800) ? x - 800 : (x < 0) ? x + 800 : x;
	pos.y = (y > 600) ? y - 600 : (y < 0) ? y + 600 : y;
}