#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
#include <list>

#include "GameObject.h"

class GameController
{
	public:
		GameController();
		~GameController();
		SDL_Texture* loadTexture(std::string path);
		static GameController* Instance()
		{
			if (instance != NULL)
			{
				return instance;
			}
			else
				return NULL;
		}
		void Draw();
		void Update(float elapsedTime);
		void handleInput(SDL_Event& e);
		void addToGameObjectList(GameObject* theObject);
		int screenHeight = 480;
		int screenWidth = 640;
	private:
		SDL_Window* gWindow = NULL;
		SDL_Renderer* gRenderer = NULL;
		bool Initialize();
		static GameController* instance;
		list<GameObject*> gameObjectList;
};

#endif GAMECONTROLLER_H