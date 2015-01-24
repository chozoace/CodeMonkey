#include "Wall.h"
#include "Visible.h"
#include "GameController.h"

Wall::Wall(float xPos, float yPos, int theId)
{
	_xPosition = xPos;
	_yPosition = yPos;
	id = theId;
	_t = new Tickable(this);
	_v = new Visible(this);
	_v->setTexture(GameController::Instance()->loadTexture("Wall.png"));

	switch (theId)
	{
		case 1:
			break;
	}
}

void Wall::Initialize(float xPos, float yPos, int theId)
{
	_xPosition = xPos;
	_yPosition = yPos;
	_width = 64;
	_height = 64;
	id = theId;
	_t = new Tickable(this);
	_v = new Visible(this);
	_v->setTexture(GameController::Instance()->loadTexture("Wall.png"));
	switch (theId)
	{
	case 1:
		break;
	}
}

Wall::~Wall()
{

}