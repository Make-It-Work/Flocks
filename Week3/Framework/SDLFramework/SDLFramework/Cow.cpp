#include "Cow.h"
#include <unordered_map>
#include <queue>
#include "Edge.h"
#include "WanderingState.h"
#include "SearchingState.h"
#include "HuntingState.h"
#include "AnimalState.h"
#include "Item.h"

Cow::Cow(Vertex* start)
{
	position = start;
	current_state = HuntingState::cowHuntingInstance();
}


Cow::~Cow()
{
}

void Cow::update() {
	if (sleepTimer > 0)
	{
		sleepTimer--;
	}else if (current_state != nullptr) {
		position = current_state->execute(this);
	}
}

void Cow::changeState(AnimalState* new_state) {
	current_state->exit(this);
	current_state = new_state;
	new_state->enter(this);
}