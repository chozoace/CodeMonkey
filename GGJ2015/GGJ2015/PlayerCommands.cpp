#include "Command.h"
#include "Player.h"

void RightCommand::rightMove(GameObject* theObject)
{	
	//GetCurrentCell
	//Check Cell to the right
	//if empty; move to cell
	//else; dont move

	//temp movement
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() + temp->getMoveSpeed());
}

void RightCommand::rightMoveRelease(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() - temp->getMoveSpeed());
}

void LeftCommand::leftMove(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() - temp->getMoveSpeed());
}

void LeftCommand::leftMoveRelease(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() + temp->getMoveSpeed());
}

void UpCommand::upMove(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() - temp->getMoveSpeed());
}

void UpCommand::upMoveRelease(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() + temp->getMoveSpeed());
}

void DownCommand::downMove(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() + temp->getMoveSpeed());
}

void DownCommand::downMoveRelease(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() - temp->getMoveSpeed());
}