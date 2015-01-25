#include "Cell.h"
#include "GameController.h"

Cell::Cell()
{
	myObject = NULL;
	_cellType = Cell::Empty;
}


Cell::~Cell()
{
	if (myObject != NULL)
	{
		delete myObject;
	}
}

int Cell::GetCellX()
{
	return _cellX;
}

int Cell::GetCellY()
{
	return _cellY;
}

GameObject* Cell::GetGameObject()
{
	return myObject;
}

void Cell::SetGameObject(GameObject* obj)
{
	myObject = obj;
}

void Cell::RemoveGameObject()
{
	//delete Object
	if (myObject != NULL)
	{
		GameController::Instance()->removeFromGameObjectList(myObject);
		delete myObject;
		myObject = NULL;
		_cellType = Cell::Empty;
	}
}
