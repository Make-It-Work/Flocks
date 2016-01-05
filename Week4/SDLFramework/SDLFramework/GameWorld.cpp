#include "GameWorld.h"
#include "BaseGameEntity.h"
#include "Cow.h"
#include "Vector2.h"
#include "math.h"
GameWorld::GameWorld()
{
}

GameWorld::~GameWorld()
{
}

std::vector<Cow*> GameWorld::getCows(Vector2 position, int radius) {
	std::vector<Cow*> c;
	for each(BaseGameEntity* obj in gameObjects) {
		Cow* cow = dynamic_cast<Cow*>(obj);
		if (cow != NULL) {
			if (pow((cow->getPos().x - position.x),2) + pow((cow->getPos().y - position.y),2) < pow(radius,2)) {
				//This cow is in radius
				c.push_back(cow);
			}
		}
	}
	return c;
}