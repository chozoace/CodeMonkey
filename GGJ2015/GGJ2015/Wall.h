#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
	public:
		Wall(){}
		Wall(int xPos, int yPos, int theId);
		void Initialize(int xPos, int yPos, int theId);
		virtual ~Wall();
	protected:
		int id;
};

#endif WALL_H