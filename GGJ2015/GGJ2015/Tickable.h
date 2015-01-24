#ifndef TICKABLE_H
#define TICKABLE_H

using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include <string>

class Tickable : public Component
{
	public:
		Tickable();
		Tickable(GameObject *theObject);
		virtual ~Tickable();
		virtual void Update(float timeElapsed);
		void setXVelocity(float value) { xVelocity = value; }
		void setYVelocity(float value) { yVelocity = value; }
		float getXVelocity() { return xVelocity; }
		float getYVelocity() { return yVelocity; }
		int getMoveSpeed(){ return moveSpeed; }
	protected:
		bool counter = false;
		int moveSpeed = 1000;
		float xVelocity = 0;
		float yVelocity = 0;
};

#endif TICKABLE_H