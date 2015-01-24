#include <SDL.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
#include "GameController.h"

int main(int argc, char* args[])
{
	bool running = true;
	SDL_Event e;
	GameController gameController;
	float lastTime = (((float)clock()) / CLOCKS_PER_SEC);
	float minTimeStep = (1 / 60);

	while (running)
	{
		float current = (((float)clock()) / CLOCKS_PER_SEC);
		float elapsed = (current - lastTime);
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
			else
			{
				gameController.handleInput(e);
			}
		}
		gameController.Update(elapsed);
		gameController.Draw();
		lastTime = current;
		//if elapsed < 1/max fps, sleep
		if (elapsed < minTimeStep)
		{
			Sleep((minTimeStep - elapsed) * 1000);
		}
	}

	return 0;
}