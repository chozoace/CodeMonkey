#include "GameObject.h"
#include "Command.h"

GameObject::GameObject()
{

}

GameObject::GameObject(Visibility* v, Tickable* t)
{
	_v = v;
	_t = t;
}

GameObject::~GameObject()
{
	if (_v != NULL)
		delete _v;
	if (_t != NULL)
		delete _t;
	if (upCommand != NULL)
		delete upCommand;
	if (downCommand != NULL)
		delete downCommand;
	if (leftCommand != NULL)
		delete leftCommand;
	if (rightCommand != NULL)
		delete rightCommand;
}

void GameObject::moveWall(int direction)
{
	//1 = up
	//2 = right
	//3 = down
	//4 = left
	if (pushable)
	{
		switch (direction)
		{
		case 1:
			upCommand->Execute(this);
			break;
		case 2:
			printf("push called\n");
			rightCommand->Execute(this);
			break;
		case 3:
			downCommand->Execute(this);
			break;
		case 4:
			leftCommand->Execute(this);
			break;
		}
		detectCell();
	}
}

void GameObject::detectCell()
{
	//Used mostly for ifs, acts like a trigger
	//Pushable wall will check after it has moved
	//if it lands on a cell with a detectWall
	//and the detect wall's "answer" is the same as
	//the pushable walls ID, DetectWall will trigger "Action"
}

void GameObject::Action()
{
	//switch statement on id determines what the action is
	//Action can destroy other blocks
	//Loop through the array of cells, delete all gameObjects with a specific ID
	//using cells getGameObject and deleteGameObject
}

void GameObject::Update(float timeElapsed)
{
	_t->Update(timeElapsed);
}

void GameObject::Draw(SDL_Renderer* theRenderer)
{
	_v->Draw(theRenderer);
}