#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include "Command.h"


class Wall : public GameObject
{
	public:
		Wall(){}
		Wall(float xPos, float yPos, int theId);
		void Initialize(float xPos, float yPos, int theId);
		virtual ~Wall();
		void destroy();
		void moveWall(int direction);
		bool isPushable() { return pushable; }
		void detectCell();
	protected:
};

#endif WALL_H