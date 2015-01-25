#include "Command.h"
#include "Player.h"
#include "Cell.h"
#include "Grid.h"
#include <time.h>

void wait(float seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait){/*wait*/}
}

void RightCommand::rightMove(GameObject* theObject)
{	
	//Get current Cell
	movingRight = true;
	Cell* myCell = NULL;
	myCell = Grid::Instance()->GetCell(theObject->getXPos() / 64, theObject->getYPos() / 64);
	//check neighbor
	Cell* neighbor = NULL;
	neighbor = Grid::Instance()->GetNeighborCell(myCell, 1, 0);
	//if Wall do nothing
	if (neighbor->_cellType == Cell::Wall)
	{
		if (theObject->getId() == 100)
		{
			printf("wall\n");
		}
	}
	else if (neighbor->_cellType == Cell::Pushable)
	{
		if (theObject->getId() == 100)
		{
			Cell* pushDestination = Grid::Instance()->GetNeighborCell(myCell, 2, 0);
			if (pushDestination->_cellType == Cell::Empty)
			{
				printf("pushable\n");
				GameObject* pushObject = neighbor->GetGameObject();
				pushObject->moveWall(2);
				pushDestination->SetGameObject(pushObject);
				pushDestination->_cellType = Cell::Pushable;
				neighbor->SafeRemoveGameObject();
				theObject->setXPos(theObject->getXPos() + 64);
			}
		}
	}
	else if (neighbor ->_cellType == Cell::Empty)
	{
		theObject->setXPos(theObject->getXPos() + 64);
	}

	//temp movement
	//Tickable* temp = theObject->getTickableComponent();
	//theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() + temp->getMoveSpeed());
}

void RightCommand::rightMoveRelease(GameObject* theObject)
{
	movingRight = false;

	//Tickable* temp = theObject->getTickableComponent();
	//theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() - temp->getMoveSpeed());
}

void LeftCommand::leftMove(GameObject* theObject)
{
	movingLeft = true;
	Cell* myCell = NULL;
	myCell = Grid::Instance()->GetNearestCell(theObject->getXPos(), theObject->getYPos());
	//check neighbor
	Cell* neighbor = NULL;
	neighbor = Grid::Instance()->GetNeighborCell(myCell, -1, 0);
	if (neighbor->_cellType == Cell::Wall)
	{
		if (theObject->getId() == 100)
		{
			printf("wall\n");
		}
	}
	else if (neighbor->_cellType == Cell::Pushable)
	{
		printf("pushable\n");
		if (theObject->getId() == 100)
		{
			Cell* pushDestination = Grid::Instance()->GetNeighborCell(myCell, -2, 0);
			if (pushDestination->_cellType == Cell::Empty)
			{
				GameObject* pushObject = neighbor->GetGameObject();
				pushObject->moveWall(4);
				pushDestination->SetGameObject(pushObject);
				pushDestination->_cellType = Cell::Pushable;
				neighbor->SafeRemoveGameObject();
				theObject->setXPos(theObject->getXPos() - 64);
			}
		}
	}
	else if (neighbor->_cellType == Cell::Empty)
	{
		theObject->setXPos(theObject->getXPos() - 64);
	}

	//Tickable* temp = theObject->getTickableComponent();
	//theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() - temp->getMoveSpeed());
}

void LeftCommand::leftMoveRelease(GameObject* theObject)
{
	movingLeft = false;

	//Tickable* temp = theObject->getTickableComponent();
	//theObject->getTickableComponent()->setXVelocity(temp->getXVelocity() + temp->getMoveSpeed());
}

void UpCommand::upMove(GameObject* theObject)
{
	movingUp = true;
	Cell* myCell = NULL;
	myCell = Grid::Instance()->GetNearestCell(theObject->getXPos(), theObject->getYPos());
	//check neighbor
	Cell* neighbor = NULL;
	neighbor = Grid::Instance()->GetNeighborCell(myCell, 0, -1);
	if (neighbor->_cellType == Cell::Wall)
	{
		if (theObject->getId() == 100)
		{
			printf("wall\n");
		}
	}
	else if (neighbor->_cellType == Cell::Pushable)
	{
		if (theObject->getId() == 100)
		{
			Cell* pushDestination = Grid::Instance()->GetNeighborCell(myCell, 0, -2);
			if (pushDestination->_cellType == Cell::Empty)
			{
				GameObject* pushObject = neighbor->GetGameObject();
				pushObject->moveWall(1);
				pushDestination->SetGameObject(pushObject);
				pushDestination->_cellType = Cell::Pushable;
				neighbor->SafeRemoveGameObject();
				theObject->setYPos(theObject->getYPos() - 64);
			}
		}

	}
	else if (neighbor->_cellType == Cell::Empty)
	{
		theObject->setYPos(theObject->getYPos() - 64);
	}

	//Tickable* temp = theObject->getTickableComponent();
	//theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() - temp->getMoveSpeed());
}

void UpCommand::upMoveRelease(GameObject* theObject)
{
	movingUp = false;

	//Tickable* temp = theObject->getTickableComponent();
	//theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() + temp->getMoveSpeed());
}

void DownCommand::downMove(GameObject* theObject)
{
	movingDown = true;
	Cell* myCell = NULL;
	myCell = Grid::Instance()->GetNearestCell(theObject->getXPos(), theObject->getYPos());
	//check neighbor
	Cell* neighbor = NULL;
	neighbor = Grid::Instance()->GetNeighborCell(myCell, 0, 1);
	if (neighbor->_cellType == Cell::Wall)
	{
		if (theObject->getId() == 100)
		{
			printf("wall\n");
		}
	}
	else if (neighbor->_cellType == Cell::Pushable)
	{
		printf("pushable\n");
		if (theObject->getId() == 100)
		{
			Cell* pushDestination = Grid::Instance()->GetNeighborCell(myCell, 0, 2);
			if (pushDestination->_cellType == Cell::Empty)
			{
				GameObject* pushObject = neighbor->GetGameObject();
				pushObject->moveWall(3);
				pushDestination->SetGameObject(pushObject);
				pushDestination->_cellType = Cell::Pushable;
				neighbor->SafeRemoveGameObject();
				theObject->setYPos(theObject->getYPos() + 64);
			}
		}
	}
	else if (neighbor->_cellType == Cell::Empty)
	{
		theObject->setYPos(theObject->getYPos() + 64);
	}

	//Tickable* temp = theObject->getTickableComponent();
	//theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() + temp->getMoveSpeed());
}

void DownCommand::downMoveRelease(GameObject* theObject)
{
	Tickable* temp = theObject->getTickableComponent();
	theObject->getTickableComponent()->setYVelocity(temp->getYVelocity() - temp->getMoveSpeed());
}