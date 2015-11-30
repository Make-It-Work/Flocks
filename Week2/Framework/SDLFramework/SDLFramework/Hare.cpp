#include "Hare.h"
#include "WanderingState.h"

Hare::Hare(Vertex* start)
{
	position = start;
	current_state = WanderingState::cowWanderingInstance();
}


Hare::~Hare()
{
}

void Hare::makeAMove(Vertex* target)
{
	position = target;
}

void Hare::changeState(AnimalState* new_state) {
	current_state->exit(this);
	current_state = new_state;
	new_state->enter(this);
}

void Hare::update() {
	if (current_state != nullptr) {
		position = current_state->execute(this);
	}
}