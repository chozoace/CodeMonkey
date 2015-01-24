#include "GameController.h"
#include "Background.h"
#include "Player.h"

Player* thePlayer;
Background* theBackground;
GameController* GameController::instance = NULL;
PlayerController* theController;

GameController::GameController()
{
	if (!Initialize())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		thePlayer = new Player(100, 100);
		theController = thePlayer->getPlayerController();
		//theBackground = new Background("Background.png");
		//myGrid = new Grid();
		//myGrid->Initialize("TestXml.xml");
	}
}

GameController::~GameController()
{
	delete theBackground;
	//delete myGrid;
	delete thePlayer;
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	gWindow = NULL;
	gRenderer = NULL;
	while (!gameObjectList.empty())
	{
		gameObjectList.pop_back();
	}
	IMG_Quit();
	SDL_Quit();
}

bool GameController::Initialize()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Code Monkey", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				instance = this;
			}
		}
	}
	return success;
}

void GameController::addToGameObjectList(GameObject* theObject)
{
	gameObjectList.push_back(theObject);
}

SDL_Texture* GameController::loadTexture(std::string path)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	
	return newTexture;
}

void GameController::handleInput(SDL_Event& e)
{
	theController->handleInput(e);
}

void GameController::Update(float elapsedTime)
{
	list<GameObject*>::iterator iter;
	for (iter = gameObjectList.begin(); iter != gameObjectList.end(); iter++)
	{
		(*iter)->Update(elapsedTime);
	}

}

void GameController::Draw()
{
	SDL_RenderClear(gRenderer);

	list<GameObject*>::iterator iter;
	for (iter = gameObjectList.begin(); iter != gameObjectList.end(); iter++)
	{
		(*iter)->Draw(gRenderer);
	}

	SDL_RenderPresent(gRenderer);
}