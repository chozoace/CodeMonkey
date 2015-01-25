#include "Wall.h"
#include "Visible.h"
#include "GameController.h"

Wall::Wall(float xPos, float yPos, int theId)
{

}

void Wall::Initialize(float xPos, float yPos, int theId, int theValue)
{
	isWall = true;
	_xPosition = xPos;
	_yPosition = yPos;
	_width = 64;
	_height = 64;
	id = theId;
	_t = new Tickable(this);
	_v = new Visible(this);
	blockValue = theValue;

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
			blockValue = -1;
			break;
		case 4://locked
			_v->setTexture(GameController::Instance()->loadTexture("Lock.png"));
			break;
		case 5://else
			break;
		case 6://if
			_v->setTexture(GameController::Instance()->loadTexture("If.png"));
			break;
		case 7://check equal (destroys 4)
			_v->setTexture(GameController::Instance()->loadTexture("IfEqual.png"));
			break;
		case 8://equal image
			_v->setTexture(GameController::Instance()->loadTexture("EqualBlock.png"));
			break;
		case 9://assign block on detect
			break;
		case 10://first condition
			break;
		case 11://second condition
			break;
		case 12://value containing 4
			_v->setTexture(GameController::Instance()->loadTexture("4Block.png"));
			blockValue = 4;
			break;
		case 13://value containing 10
			_v->setTexture(GameController::Instance()->loadTexture("10Block.png"));
			blockValue = 10;
			break;
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