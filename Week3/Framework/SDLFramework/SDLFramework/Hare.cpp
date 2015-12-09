#include "Hare.h"
#include "WanderingState.h"
#include "Edge.h"
#include "Cow.h"
#include "SearchingState.h"
#include "HuntingState.h"
#include "Item.h"
#include "FleeingState.h"


Hare::Hare(Vertex* start)
{
	position = start;
	current_state = WanderingState::hareWanderingInstance();
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
	if (countHelper != "none")
		counter++;
	if (counter == 20)
	{
		counter = 0;
		countHelper = "none";
		current_state = WanderingState::hareWanderingInstance();
	}
	if (countHelper == "flee")
	{
		fleeSuccess++;
	}
	else if (countHelper == "gun")
	{
		gunSuccess++;
	}
	else if (countHelper == "pill")
	{
		pillSuccess++;
	}
	if (cowClose && gun->hasOwner() || pill->hasOwner())
	{
		counter = 0;
		countHelper == "none";
		if (gun->hasOwner())
		{
			printf("cow has been shot");

		}
		else {
			prey->sleepTimer = 5;
		}
		pill->setOwner(nullptr);
		gun->setOwner(nullptr);
	}
	if (cowClose && counter == 0) {
		int fleeWeight, pillWeight, gunWeight;
		gunWeight = (gunSuccess > pillSuccess) ? (gunSuccess > fleeSuccess) ? 5 : 3 : 2 ;
		pillWeight = (pillSuccess > gunSuccess) ? (pillSuccess > fleeSuccess) ? 5 : 3 : 2;
		fleeWeight = (fleeSuccess > pillSuccess) ? (fleeSuccess > gunSuccess) ? 5 : 3 : 2;
		printf("gw %i pw %i fw %i \n ", gunWeight, pillWeight, fleeWeight);
		int total = gunWeight + pillWeight + fleeWeight;
		int r = 1 + rand() % total;
		printf("random %i | g %i p %i f %i \n", r, gunSuccess, pillSuccess, fleeSuccess);
		bool chosen = false;
		if (r <= fleeWeight && !chosen)
		{	//get out!
			countHelper = "flee";
			current_state = FleeingState::hareFleeingInstance();
			chosen = true;
		}
		r -= fleeWeight;
		printf("%i \n", r);
		if (r <= gunWeight && !chosen)
		{	//gun!
			countHelper = "gun";
			goal = gun;
			current_state = SearchingState::hareSearchingInstance();
			chosen = true;
		}
		r -= gunWeight;
		printf("%i \n", r);
		if (r <= pillWeight && !chosen)
		{	//sleeping pill
			countHelper = "pill";
			goal = pill;
			current_state = SearchingState::hareSearchingInstance();
			chosen = true;
		}
		printf("state %s r %i", countHelper.c_str(), r);

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
}