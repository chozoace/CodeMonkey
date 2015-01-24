#pragma once
#include "GameObject.h"

class Cell
{
public:
	Cell();
	~Cell();

	enum class CellType { Wall };

	CellType _cellType;

private:
	int _cellX;
	int _cellY;
	GameObject* myObject;
};

