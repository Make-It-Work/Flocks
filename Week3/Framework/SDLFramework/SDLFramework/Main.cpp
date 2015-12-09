#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "Graph.h"
#include "Pill.h"
#include "Cow.h"
#include "Hare.h"
#include "DrawService.h"
#include "Weapon.h"
#include "Pill.h"

Graph* g = nullptr;
Weapon* weapon = nullptr;
Pill* p = nullptr;
Hare* hare = nullptr;
Cow* cow = nullptr;
int gSize = 10;

int main(int args[])
{
	srand(time(NULL));
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	
	g = new Graph(gSize);
	weapon = new Weapon(g->vertices[rand() % g->vertices.size()]);
	p = new Pill(g->vertices[rand() % g->vertices.size()]);
	hare = new Hare(g->vertices[rand() % g->vertices.size()]);
	cow = new Cow(g->vertices[rand() % g->vertices.size()]);
	cow->goal = (Item*)p;
	cow->prey = hare;
	hare->prey = cow;
	hare->pill = p;
	hare->gun = weapon;

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				int code = event.key.keysym.scancode;
				//printf("code %i \n", code);
				if (code == 41 || code == 87 || code == 86)
				{
					if (code == 87) gSize++;
					if (code == 86 && gSize > 2) gSize--;
					printf("building a new graph of %i vertices \n", gSize);
					g = new Graph(gSize);

					cow->setPosition(g->vertices.front());
					hare->setPosition(g->vertices[rand() % g->vertices.size()]);
					weapon->setLocation(g->vertices[rand() % g->vertices.size()]);
					p->setLocation(g->vertices[rand() % g->vertices.size()]);
					weapon->setOwner(nullptr);
					p->setOwner(nullptr);
				}
				else
				{
					cow->update();
					hare->update();
				}
				
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));

		DrawService::cow(application, cow->getPosition(), cow->getState(), cow->sleepTimer);
		DrawService::hare(application, hare->getPosition(), hare->getState());
		if (!p->hasOwner()) { DrawService::pill(application, p->getLocation()); }
		if (!weapon->hasOwner()) { DrawService::weapon(application, weapon->getLocation()); }
		cow->getPosition()->print(application);
		
		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		if (cow->getPosition() == hare->getPosition() && cow->getState() != "wandering" && hare->getState() != "wandering") {
			g = new Graph(gSize);
			cow->setPosition(g->vertices.front());
			hare->setPosition(g->vertices[rand() % g->vertices.size()]);
			weapon->setLocation(g->vertices[rand() % g->vertices.size()]);
			p->setLocation(g->vertices[rand() % g->vertices.size()]);
			weapon->setOwner(nullptr);
			p->setOwner(nullptr);
		}


		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}
