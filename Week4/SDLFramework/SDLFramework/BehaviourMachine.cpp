#include "BehaviourMachine.h"
#include "Cow.h"
#include "Hare.h"

Vector2 BehaviourMachine::Behave(Cow* c)
{
	return c->getSteering()->calculate();
}

Vector2 BehaviourMachine::Behave(Hare* h)
{
	return h->getSteering()->calculate();
}