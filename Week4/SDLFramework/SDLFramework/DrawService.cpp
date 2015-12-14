#include "DrawService.h"
#include <string>
#include "BaseGameEntity.h"
#include "Cow.h"
#include "Hare.h"

void DrawService::point(FWApplication* app, Vector2 pt)
{
	app->DrawRect(pt.x, pt.y, 5, 5, true);
}


void DrawService::hare(FWApplication* app, Hare h) 
{
	app->DrawTexture(app->LoadTexture("rabbit-2.png"), h.getPos().x, h.getPos().y, 48, 48);
}

void DrawService::cow(FWApplication* app, Cow c)
{
	app->DrawTexture(app->LoadTexture("cow-2.png"), c.getPos().x, c.getPos().y, 48, 48);
}