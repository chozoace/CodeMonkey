#pragma once
#include "GameObject.h"

class Cell
{
public:
	Cell();
	~Cell();

	enum class CellType { Wall };

	CellType _cellType;

	int GetCellX();
	int GetCellY();
	GameObject* GetGameObject();
	void SetGameObject(GameObject* obj);

private:
	int _cellX;
	int _cellY;
	GameObject* myObject;
};

