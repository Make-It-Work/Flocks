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

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	Vector2 v2 = Vector2(-8, -4);
	printf("v2 l %f \n", (double)v2.length());
	v2.truncate(3);
	printf("v2 l %f x %f y %f \n", (double)v2.length(), v2.x, v2.y);
	std::vector<Cow*>* cows = new std::vector < Cow*>();
	Hare me = Hare(Vector2(200,400));
	Cow c = Cow(Vector2(400, 400), &me);
	me.prey = &c;
	printf("x %f y %f \n", me.getPos().x, me.getPos().y);
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
		me.update(0.5);
		c.update(0.5);
		//printf("x %f y %f \n", me.getPos().x, me.getPos().y);
		
		application->SetColor(Color(0, 0, 0, 255));
		DrawService::hare(application, me);
		DrawService::cow(application, c);
		DrawService::point(application, c.projection);
		//printf("hx %f hy %f \n", me.getPos().x, me.getPos().y);
		// For the background
		application->SetColor(Color(255, 255, 255, 255));
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}