#include "PlayerController.h"
#include "Command.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Camera.h"
#include "GameController.h"

int screenWidth;
int screenHeight;
int levelWidth;
int levelHeight;

PlayerController::PlayerController(GameObject* theObject)
{
	myObject = theObject;
	moveSpeed = 300;
	rightCommand = new RightCommand();
	leftCommand = new LeftCommand();
	upCommand = new UpCommand();
	downCommand = new DownCommand();

	screenWidth = GameController::Instance()->screenWidth;
	screenHeight = GameController::Instance()->screenHeight;
	levelWidth = GameController::Instance()->levelWidth;
	levelHeight = GameController::Instance()->levelHeight;
}

PlayerController::~PlayerController()
{
	delete rightCommand;
	delete leftCommand;
	delete upCommand;
	delete downCommand;
}

void PlayerController::Update(float timeElapsed)
{
	//Set Current Cell
	currentCell = Grid::Instance()->GetNearestCell(myObject->getXPos(), myObject->getYPos());

	//Movement
	//myObject->setXPos(myObject->getXPos() + (xVelocity * timeElapsed));
	//myObject->setYPos(myObject->getYPos() + (yVelocity * timeElapsed));

	//Check collision and resolve
	

	//center camera over player
	Camera::Instance()->setXPosition((myObject->getXPos() + myObject->getWidth() / 2) - screenWidth / 2);
	Camera::Instance()->setYPosition((myObject->getYPos() + myObject->getHeight() / 2) - screenHeight / 2);

	int camX = Camera::Instance()->getXPosition();
	int camY = Camera::Instance()->getYPosition();

	//Keep camera in bounds
	if (camX < 0)
	{
		Camera::Instance()->setXPosition(0);
	}
	if (camY < 0)
	{
		Camera::Instance()->setYPosition(0);
	}
	if (camX + screenWidth > levelWidth)
	{
		Camera::Instance()->setXPosition(levelWidth - screenWidth);
	}
	if (camY + screenHeight > levelHeight)
	{
		Camera::Instance()->setYPosition(levelHeight - screenHeight);
	}
}

void PlayerController::handleInput(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			case RIGHT_KEY:
				rightCommand->Execute(myObject);
				break;
			case LEFT_KEY:
				leftCommand->Execute(myObject);
				break;
			case UP_KEY:
				upCommand->Execute(myObject);
				break;
			case DOWN_KEY:
				downCommand->Execute(myObject);
				break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			case RIGHT_KEY:
				rightCommand->ExecuteRelease(myObject);
				break;
			case LEFT_KEY:
				leftCommand->ExecuteRelease(myObject);
				break;
			case DOWN_KEY:
				downCommand->ExecuteRelease(myObject);
				break;
			case UP_KEY:
				upCommand->ExecuteRelease(myObject);
				break;
		}
	}
}