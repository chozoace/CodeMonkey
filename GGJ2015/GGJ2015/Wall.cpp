#include "Wall.h"
#include "Visible.h"
#include "GameController.h"

Wall::Wall(float xPos, float yPos, int theId)
{
	isWall = true;
	_xPosition = xPos;
	_yPosition = yPos;
	id = theId;
	_t = new Tickable(this);
	_v = new Visible(this);

	switch (theId)
	{
		//Regular Wall
		case 1:
			_v->setTexture(GameController::Instance()->loadTexture("Wall.png"));
			break;
		//Pushable Wall
		case 3:
			_v->setTexture(GameController::Instance()->loadTexture("Pushable.png"));
			pushable = true;
			break;
			//if pushable; attach different tickable component
		//Locked Wall
	}

	upCommand = new UpCommand();
	downCommand = new DownCommand();
	rightCommand = new RightCommand();
	leftCommand = new LeftCommand();
}

void Wall::Initialize(float xPos, float yPos, int theId)
{
	isWall = true;
	_xPosition = xPos;
	_yPosition = yPos;
	_width = 64;
	_height = 64;
	id = theId;
	_t = new Tickable(this);
	_v = new Visible(this);

	switch (theId)
	{
		//Regular Wall
		case 1:
			_v->setTexture(GameController::Instance()->loadTexture("Wall.png"));
			break;
		//Pushable Wall
		case 3:
			_v->setTexture(GameController::Instance()->loadTexture("Pushable.png"));
			pushable = true;
			break;
		//Locked Wall
	}

	upCommand = new UpCommand();
	downCommand = new DownCommand();
	rightCommand = new RightCommand();
	leftCommand = new LeftCommand();
}

void Wall::destroy()
{
	
}

Wall::~Wall()
{
	delete rightCommand;
	delete leftCommand;
	delete upCommand;
	delete downCommand;
}