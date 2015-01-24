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

void Grid::Initialize(const char* level)
{
	_columns = XmlParser::GetIntVariable("width", level);
	_rows = XmlParser::GetIntVariable("height", level);
	_cellSize = XmlParser::GetIntVariable("tilewidth", level);

	_cells = new Cell*[_rows , _columns] {};

	int* nodes = XmlParser::GetNodes(level);

	/*printf("Size: %d\n", nodes.size());*/
	printf("Cell Size: %d\n", _cellSize);

	//Wall *theWall = new Wall();
	for (int x = 0; x < _columns; x++)
	{
		for (int y = 0; y < _rows; y++)
		{
			Cell* cell = new Cell();
			_cells[x , y] = cell;
			Wall *theWall = new Wall();
			theWall->Initialize(x * _cellSize, y * _cellSize, 1);
			GameController::Instance()->addToGameObjectList(theWall);
		}
	}

}
