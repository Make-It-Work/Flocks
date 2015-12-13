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
	Vector2 v2 = Vector2(8, 4);
	printf("v2 l %f \n", (double)v2.length());
	v2.truncate(3);
	printf("v2 l %f x %f y %f \n", (double)v2.length(), v2.x, v2.y);

	Hare me = Hare(Vector2(1,0), Vector2(0,1), Vector2(100,100));
	printf("x %i y %i \n", me.getPos().x, me.getPos().y);
	me.update(0.0001);
	printf("x %i y %i \n", me.getPos().x, me.getPos().y);
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
		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to KMint", 800 / 2, 600 / 2);
		DrawService::basegame(application, me);
		// For the background
		application->SetColor(Color(255, 255, 255, 255));
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}