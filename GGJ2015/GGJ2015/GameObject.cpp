#include "GameObject.h"
#include "Command.h"
#include "Grid.h"

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
	printf("detect\n");
	if (getId() == 3)
	{
		Cell* theCell = Grid::Instance()->GetCell(getXPos() / 64, getYPos() / 64);
		GameObject* theObject = theCell->GetGameObject();
		if (theObject != NULL)
		{
			if (theObject->getId() == 3)//only assigns once
			{
				printf("3333\n");
			}
			if (theObject->getId() == 9)//only assigns once
			{
				Cell* valueCell = Grid::Instance()->GetNeighborCell(theCell, 2, 0);
				GameObject* valueObject;
				valueObject = valueCell->GetGameObject();
				blockValue = valueObject->getBlockValue();
				printf("new Value %d\n", blockValue);
			}
			if (theObject->getId() == 10)
			{
				Cell* valueCell = Grid::Instance()->GetNeighborCell(theCell, 2, 0);
				GameObject* valueObject = valueCell->GetGameObject();
				if (valueObject != NULL)
				{
					if (blockValue == valueObject->getBlockValue())
					{
						printf("alright!\n");
						Action(10);
					}
					else
					{
						printf("nope\n");
					}
				}
			}
		}
		else
		{
			printf("object is null\n");
		}
	}
	
}

void GameObject::Action(int actionId)
{
	//switch statement on id determines what the action is
	//Action can destroy other blocks
	//Loop through the array of cells, delete all gameObjects with a specific ID
	//using cells getGameObject and deleteGameObject
	switch (actionId)
	{
		case 10:
			//destroy all id 4 tiles
			Cell*** cells = Grid::Instance()->getCellArray();
			for (int counterY = 0; counterY < Grid::Instance()->GetRows(); counterY++)
			{
				for (int counterX = 0; counterX < Grid::Instance()->GetColumns(); counterX++)
				{
					GameObject* theObject = cells[counterX][counterY]->GetGameObject();
					if (theObject != NULL)
					{
						if (theObject->getId() == 4)
						{
							printf("removed\n");
							cells[counterX][counterY]->RemoveGameObject();
						}
					}
				}
			}
			break;
	}
}

void GameObject::Update(float timeElapsed)
{
	_t->Update(timeElapsed);
}

void GameObject::Draw(SDL_Renderer* theRenderer)
{
	_v->Draw(theRenderer);
}