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
	int gSize = 10;
	/*
	Vertex* v1 = new Vertex(30, 100);
	Vertex* v2 = new Vertex(500, 400);

	v1->connect(v2);
	Edge* e2 = v1->edges.front();
	printf("weight %i should be 7 \n", e2->getWeight());
	printf("estimate %i should be same as weight \n", v1->estimate(v2));
	*/
	Graph* g = new Graph(gSize);
	Vertex* cowPosition = g->vertices.front();
	Vertex* harePosition = g->vertices[rand() % g->vertices.size()];


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
					cowPosition = g->vertices.front();
					harePosition = g->vertices[rand() % g->vertices.size()];
				}
				else
				{
					if (harePosition == cowPosition)
					{
						while((harePosition == cowPosition))harePosition = g->vertices[rand() % g->vertices.size()];
					}
					else
					{
						Vertex* next = cowPosition->aMove(harePosition);
						if (next != nullptr)
						{
							cowPosition = next;
						}
					}
				}
				
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

		DrawService::cow(application, cowPosition);
		DrawService::hare(application, harePosition);
		cowPosition->print(application);
		
		// For the background
		application->SetColor(Color(255, 255, 255, 255));


		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}

