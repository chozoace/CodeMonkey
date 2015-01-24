#include "Grid.h"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

#include "XmlParser.h"
#include "GameController.h"
#include "Wall.h"

#include <iostream>

Grid::Grid()
{

}


Grid::~Grid()
{
	for (int counter = 0; counter < (_rows * _columns); counter++)
	{
		delete _cells[counter];
	}
	delete _cells;
}

int Grid::GetCellSize()
{
	return _cellSize;
}

int Grid::GetColumns()
{
	return _columns;
}

int Grid::GetRows()
{
	return _rows;
}

void Grid::Initialize(const char* level)
{
	_columns = XmlParser::GetIntVariable("width", level);
	_rows = XmlParser::GetIntVariable("height", level);
	_cellSize = XmlParser::GetIntVariable("tilewidth", level);

	_cells = new Cell*[_rows , _columns] {};

	int* nodes = XmlParser::GetNodes(level);

	int counter = 0;

	//Wall *theWall = new Wall();
	for (int y = 0; y < _rows; y++)
	{
		for (int x = 0; x < _columns; x++)
		{

			Cell* cell = new Cell();
			_cells[x, y] = cell;

			printf("Gid: %d\n", nodes[counter]);

			if (nodes[counter] == 1)
			{
				Wall *theWall = new Wall();
				theWall->Initialize(x * _cellSize, y * _cellSize, 1);
				GameController::Instance()->addToGameObjectList(theWall);

				_cells[x, y]->SetGameObject(theWall);
			}
			else if (nodes[counter] == 2)
			{

			}

			counter++;
		}
	}
}

Cell* Grid::GetCell(int x, int y)
{
	if (x < 0 || y < 0 || x > (_columns * _rows) || y >= (_columns * _rows)) return NULL;

	return _cells[x, y];
}

Cell* Grid::GetNeighborCell(Cell *targetCell, int xOffSet, int yOffSet)
{
	return GetCell(targetCell->GetCellX() + xOffSet, targetCell->GetCellY() + yOffSet);
}

Cell* Grid::GetNearestCell(int worldX, int worldY)
{
	//Offset by grid origin
	worldX -= _gridOriginX;
	worldY -= _gridOriginY;

	//Normalize by cell size
	worldX /= _cellSize;
	worldY /= _cellSize;

	int xCell = (int)floor(worldX);
	int yCell = (int)floor(worldY);

	return GetCell(xCell, yCell);
}
