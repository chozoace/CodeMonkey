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

			switch (nodes[counter])
			{
				case 1://wall
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 1);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Wall;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 2://player
					GameController::Instance()->CreatePlayer(x * _cellSize, y * _cellSize);
					break;
				case 3://pushable variable
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 3);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Pushable;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 4://locked
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 4);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Wall;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 5://else
					break;
				case 6://if
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 6);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Wall;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 7://check equal (destroys 4)
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 7);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Wall;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 8://equal image
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 8);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Wall;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 9://assign block on detect
					{
						printf("made\n");
						Wall *theWall = new Wall();
						theWall->Initialize(x*_cellSize, y * _cellSize, 9);

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 10://first condition
					{
						printf("made\n");
						Wall *theWall = new Wall();
						theWall->Initialize(x*_cellSize, y * _cellSize, 10);

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 11://second condition
					break;
				case 12://value containing 4
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 12);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Wall;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
				case 13://value containing 10
					{
						Wall *theWall = new Wall();
						theWall->Initialize(x * _cellSize, y * _cellSize, 13);
						GameController::Instance()->addToGameObjectList(theWall);
						_cells[x][y]->_cellType = Cell::Wall;

						_cells[x][y]->SetGameObject(theWall);
					}
					break;
			}
			counter++;
		}
	}
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
