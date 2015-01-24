#pragma once
#include "Cell.h"
#include <string>

class Grid
{
public:
	Grid();
	~Grid();

	void Initialize(const char* level);
	
	Cell GetCell(int x, int y);
	Cell GetNeighborCell(int x, int y, Cell cell);
	Cell GetNearestCell(int x, int y);

private:

	int _cellSize;
	int _columns;
	int _rows;

	Cell** _cells;

};

