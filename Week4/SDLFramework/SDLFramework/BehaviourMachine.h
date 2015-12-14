#pragma once
#include "Cow.h"
#include "Hare.h"

class BehaviourMachine
{
public:
	static Vector2 Behave(Cow* c);
	static Vector2 Behave(Hare* h);
};