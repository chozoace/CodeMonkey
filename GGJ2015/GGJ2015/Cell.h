#pragma once
#include "GameObject.h"

class Cell
{
public:
	Cell();
	~Cell();

	enum CellType { Wall, Pushable, Empty };

	CellType _cellType;

	int GetCellX();
	int GetCellY();
	void SetCellX(int value) { _cellX = value; }
	void SetCellY(int value) { _cellY = value; }
	GameObject* GetGameObject();
	void SetGameObject(GameObject* obj);
	void RemoveGameObject();
	void SafeRemoveGameObject();
private:
	int _cellX;
	int _cellY;
	GameObject* myObject;
};

