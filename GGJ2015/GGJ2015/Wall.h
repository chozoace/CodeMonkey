#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
	public:
		Wall(){}
		Wall(float xPos, float yPos, int theId);
		void Initialize(float xPos, float yPos, int theId);
		virtual ~Wall();
	protected:
		int id;
};

#endif WALL_H