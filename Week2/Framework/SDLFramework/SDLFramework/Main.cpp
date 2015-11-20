#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "Hare.h"
#include "Cow.h"
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "DrawService.h"

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
	int gSize = 10;
	
	Graph* g = new Graph(gSize);
	Cow* cow = new Cow(g->vertices[rand() % g->vertices.size()]);
	Hare* hare = new Hare(g->vertices[rand() % g->vertices.size()]);

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
				}
				else
				{
					if (hare->getPosition() == cow->getPosition())
					{
						while ((cow->getPosition() == hare->getPosition())) {
							hare->setPosition(g->vertices[rand() % g->vertices.size()]);
						};
					}
					else
					{
						cow->makeAMove(hare->getPosition());
					}
				}
				
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));

		DrawService::cow(application, cow->getPosition());
		DrawService::hare(application, hare->getPosition());
		cow->getPosition()->print(application);
		
		// For the background
		application->SetColor(Color(255, 255, 255, 255));


		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}

