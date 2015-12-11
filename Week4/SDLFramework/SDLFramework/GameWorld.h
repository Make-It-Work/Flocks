#pragma once
#include <vector>

class BaseGameEntity;
class GameWorld
{
public:
	GameWorld();
	~GameWorld();

private:
	double width;
	double height;

	std::vector<BaseGameEntity*> gameObjects;
};
