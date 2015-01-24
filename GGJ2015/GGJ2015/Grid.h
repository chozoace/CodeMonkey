#ifndef GRID_H
#define GRID_H

#pragma once
#include "Cell.h"
#include <string>

class Grid
{
public:
	Grid();
	~Grid();

	void Initialize(const char* level);
	
	Cell* GetCell(int x, int y);
	Cell* GetNeighborCell(Cell *cell, int x, int y);
	Cell* GetNearestCell(int x, int y);

	int GetCellSize();
	int GetColumns();
	int GetRows();
	int GetGridOriginX;
	int GetGridOriginY;

private:

	int _cellSize;
	int _columns;
	int _rows;

	int _gridOriginX;
	int _gridOriginY;

	Cell** _cells;

};

#endif GRID_H