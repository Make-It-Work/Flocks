#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

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
	/*
	Vertex* v1 = new Vertex(30, 100);
	Vertex* v2 = new Vertex(500, 400);

	v1->connect(v2);
	Edge* e2 = v1->edges.front();
	printf("weight %i should be 7 \n", e2->getWeight());
	printf("estimate %i should be same as weight \n", v1->estimate(v2));
	*/
	Graph* g = new Graph(5);
	Vertex* cowPosition = g->vertices.front();
	Vertex* harePosition = g->vertices.back();


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

					if (harePosition == cowPosition)
					{
					}
					harePosition = g->vertices[rand() % g->vertices.size()];
					cowPosition->aMove(harePosition, g);
					break;
				
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));
		//application->DrawText("Welcome to KMint", 800 / 2, 600 / 2);
		//draw first vertices and edges
		/*
		DrawService::DrawVert(application, v1);
		DrawService::DrawVert(application, v2);
		//DrawService::DrawVertWithEdges(application, v1);
		DrawService::DrawEdge(application, v1->edges.front());
		*/
		cowPosition->print(application);
		
		// For the background
		application->SetColor(Color(255, 255, 255, 255));


		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}

