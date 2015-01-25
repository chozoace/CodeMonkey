#include "DetectWall.h"

DetectWall::DetectWall(float xPos, float yPos, int theId)
{
	//Used mostly for ifs, acts like a trigger
	//Pushable wall will check after it has moved
	//if it lands on a cell with a detectWall
	//and the detect wall's "answer" is the same as
	//the pushable walls ID, DetectWall will trigger "Action"
}

DetectWall::~DetectWall()
{

}

void DetectWall::Action()
{
	//Action can destroy other blocks
	//Loop through the array of cells, delete all gameObjects with a specific ID
	//using cells getGameObject and deleteGameObject
}