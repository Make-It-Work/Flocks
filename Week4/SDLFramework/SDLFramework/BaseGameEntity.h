#pragma once
#include <string>
class BaseGameEntity
{
protected:
	std::string type;
	double xPos;
	double yPos;
	double boundingRadius;
	double scale;
	bool m_bTag;
public:
	BaseGameEntity();
	~BaseGameEntity();
};


