#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Vector2.h"
#include <math.h>
#include "MovingEntity.h"
#include "DrawService.h"
#include "Hare.h"
#include "Cow.h"
#include <vector>
#include "GameWorld.h"

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	GameWorld* gameWorld = new GameWorld();
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	Vector2 v2 = Vector2(-8, -4);
	printf("v2 l %f \n", (double)v2.length());
	v2.truncate(3);
	printf("v2 l %f x %f y %f \n", (double)v2.length(), v2.x, v2.y);
	std::vector<Cow*>* cows = new std::vector < Cow*>();
	Hare* me = new Hare(Vector2(200,400));
	Cow* c = new Cow(Vector2(400, 400), me);
	Cow* c1 = new Cow(Vector2(400, 450), me);
	Cow* c2= new Cow(Vector2(450, 400), me);
	Cow* c3 = new Cow(Vector2(450, 450), me);
	Cow* c4 = new Cow(Vector2(500, 400), me);
	Cow* c5 = new Cow(Vector2(500, 450), me);
	me->prey = c;

	gameWorld->addEntity(me);
	gameWorld->addEntity(c);
	gameWorld->addEntity(c1);
	gameWorld->addEntity(c2);
	gameWorld->addEntity(c3);
	gameWorld->addEntity(c4);
	gameWorld->addEntity(c5);

	c->tagNeighbours(gameWorld);
	c1->tagNeighbours(gameWorld);
	c2->tagNeighbours(gameWorld);
	c3->tagNeighbours(gameWorld);
	c4->tagNeighbours(gameWorld);
	c5->tagNeighbours(gameWorld);

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
				switch (event.key.keysym.sym){

				default:
					break;
				}
			}
		}
		//printf("x %f y %f \n", me.getPos().x, me.getPos().y);
		
		application->SetColor(Color(0, 0, 0, 255));
		DrawService::hare(application, me);
		for each (BaseGameEntity* c in gameWorld->getObjects())
		{
			c->update(0.5);
			Cow* cow = dynamic_cast<Cow*>(c);
			if (cow != NULL) {
				DrawService::cow(application, cow);
			}
		}
		for each (BaseGameEntity* c in gameWorld->getObjects())
		{
			Cow* cow = dynamic_cast<Cow*>(c);
			if (cow != NULL) {
				cow->clearNeighbours();
				cow->tagNeighbours(gameWorld);
				cow->flock();
				DrawService::cow(application, cow);
			}
		}
		DrawService::point(application, c->projection);
		//printf("hx %f hy %f \n", me.getPos().x, me.getPos().y);
		// For the background
		application->SetColor(Color(255, 255, 255, 255));
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}