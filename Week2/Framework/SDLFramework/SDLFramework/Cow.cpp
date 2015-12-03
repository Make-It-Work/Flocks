#include "Cow.h"
#include <unordered_map>
#include <queue>
#include "Edge.h"
#include "WanderingState.h"
#include "SearchingState.h"
#include "HuntingState.h"
#include "Item.h"

Cow::Cow(Vertex* start)
{
	position = start;
	current_state = WanderingState::cowWanderingInstance();
}


Cow::~Cow()
{
}

void Cow::update() {
	bored++;
	if (current_state != nullptr) {
		position = current_state->execute(this);
	}
	if (bored == 5)
	{
		changeState(SearchingState::cowSearchingInstance());
	}
	if (goal->getLocation() == getPosition())
	{
		changeState(HuntingState::cowHuntingInstance());
	}
}

void Cow::changeState(AnimalState* new_state) {
	current_state->exit(this);
	current_state = new_state;
	new_state->enter(this);
}