#include "Grid.h"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"

#include "XmlParser.h"
#include "GameController.h"
#include "Wall.h"

#include <iostream>

Grid* Grid::instance;

Grid::Grid()
{
	instance = this;
}

Grid::~Grid()
{
	int counter = 0;
	for (int counterY = 0; counterY < _rows; counterY++)
	{
		for (int counterX = 0; counterX < _columns; counterX++)
		{	
			delete _cells[counterX][counterY];
			_cells[counterX][counterY] = NULL;
			counter++;
		}
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

	_cells = new Cell**[_columns];
	for (int i = 0; i < _columns; i++)
		_cells[i] = new Cell*[_rows];

	int* nodes = XmlParser::GetNodes(level);

	int counter = 0;
	for (int y = 0; y < _rows; y++)
	{
		for (int x = 0; x < _columns; x++)
		{
			Cell* cell = new Cell();
			_cells[x][y] = cell;
			cell->SetCellX(x * _cellSize);
			cell->SetCellY(y * _cellSize);

			if (nodes[counter] == 1)
			{
				Wall *theWall = new Wall();
				theWall->Initialize(x * _cellSize, y * _cellSize, 1);
				GameController::Instance()->addToGameObjectList(theWall);
				_cells[x][y]->_cellType = Cell::Wall;

				_cells[x][y]->SetGameObject(theWall);
			}
			else if (nodes[counter] == 2)
			{
				GameController::Instance()->CreatePlayer(x * _cellSize, y * _cellSize);
			}
			else if (nodes[counter] == 3)
			{
				//pushable wall
				Wall *theWall = new Wall();
				theWall->Initialize(x * _cellSize, y * _cellSize, 3);
				GameController::Instance()->addToGameObjectList(theWall);
				_cells[x][y]->_cellType = Cell::Pushable;

				_cells[x][y]->SetGameObject(theWall);
			}

			counter++;
		}
	}

	//_cells[0][0]->RemoveGameObject();
}

Cell* Grid::GetCell(int x, int y)
{
	if (x < 0 || y < 0 || x > (_columns) || y > (_rows))
	{
		printf("returns null\n");
		return NULL;
	}

	return _cells[x][y];
}

Cell* Grid::GetNeighborCell(Cell *targetCell, int xOffSet, int yOffSet)
{
	return GetCell(targetCell->GetCellX()/64 + xOffSet, targetCell->GetCellY()/64 + yOffSet);
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
