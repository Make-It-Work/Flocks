#include "DrawService.h"
#include <string>
#include "BaseGameEntity.h"

void DrawService::basegame(FWApplication* app, BaseGameEntity be)
{
	app->DrawRect(be.getPos().x, be.getPos().y, 5, 5, true);
}