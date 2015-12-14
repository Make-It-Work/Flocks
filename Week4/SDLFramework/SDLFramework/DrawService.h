#pragma once
#include "FWApplication.h"
#include <unordered_map>
#include "BaseGameEntity.h"
#include "Hare.h"
#include "Cow.h"

class DrawService
{
public:

	static void point(FWApplication* app, Vector2 pt);
	static void hare(FWApplication* app, Hare h);
	static void cow(FWApplication* app, Cow c);
};