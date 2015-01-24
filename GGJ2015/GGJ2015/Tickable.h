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
	protected:
		bool counter = false;
};

#endif TICKABLE_H