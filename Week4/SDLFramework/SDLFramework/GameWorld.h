#pragma once
#include <vector>
#include "Vector2.h"

class Cow;
class BaseGameEntity;
class GameWorld
{
public:
	GameWorld();
	~GameWorld();

	std::vector<Cow*> getCows(Vector2 position, int radius);
	void addEntity(BaseGameEntity* ent) { gameObjects.push_back(ent); }
	std::vector<BaseGameEntity*> getObjects() { return gameObjects; }

private:
	double width = 800;
	double height = 600;

	std::vector<BaseGameEntity*> gameObjects;
};
