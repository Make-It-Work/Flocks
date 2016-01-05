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
	std::string behaviour = "";
public:
	BaseGameEntity(Vector2 position);
	virtual ~BaseGameEntity() = 0;
	virtual void update(double time_elapsed) = 0;

	void setBehaviour(std::string s) { behaviour = s; }
	std::string getBehaviour() { return behaviour; }

	Vector2 getPos() { return pos; };
};


