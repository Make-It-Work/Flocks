#pragma once
#include <string>
#include "Vector2.h"

class BaseGameEntity
{
protected:
	std::string type;
	Vector2 pos = Vector2(0,0);
	double boundingRadius;
	double scale;
	bool m_bTag;
public:
	BaseGameEntity(Vector2 position);
	~BaseGameEntity();

	Vector2 getPos() { return pos; };
};


