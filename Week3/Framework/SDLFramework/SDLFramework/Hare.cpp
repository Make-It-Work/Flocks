#include "Hare.h"
#include "WanderingState.h"
#include "Edge.h"
#include "Cow.h"
#include "SearchingState.h"
#include "HuntingState.h"
#include "Item.h"



Hare::Hare(Vertex* start)
{
	position = start;
	current_state = WanderingState::cowWanderingInstance();
}

Hare::~Hare()
{
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
	bool cowClose = false;
	for (Edge* e : position->edges) {
		if (e->getEnd(position) == prey->getPosition()) {
			cowClose = true;
		}
	}
	if (cowClose) {
		/*
		changeState(SearchingState::hareSearchingInstance());
		*/


	}
	if (gun->hasOwner()) {
		changeState(HuntingState::hareHuntingInstance());
	}
	if (position == prey->getPosition()) {
		changeState(WanderingState::hareWanderingInstance());
	}
	if (pill->hasOwner()) {
		changeState(WanderingState::hareWanderingInstance());
	}
	if (current_state->getName() == "Fleeing")
	{

	}
}