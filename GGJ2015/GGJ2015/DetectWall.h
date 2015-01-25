#ifndef DETECTWALL_H
#define DETECTWALL_H

#include "Wall.h"

class DetectWall : public Wall
{
	public:
		DetectWall(float xPos, float yPos, int theId);
		virtual ~DetectWall();
		void Action();
	private:
		//should probably be assigned things to do action to
};

#endif DETECTWALL_H