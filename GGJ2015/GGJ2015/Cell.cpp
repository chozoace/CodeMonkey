#include "Cell.h"

Cell::Cell()
{
	myObject = NULL;
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
