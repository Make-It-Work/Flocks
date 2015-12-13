#pragma once
#include <vector>

class BaseGameEntity;
class GameWorld
{
public:
	GameWorld();
	~GameWorld();

private:
	double width = 800;
	double height = 600;

	std::vector<BaseGameEntity*> gameObjects;
};
