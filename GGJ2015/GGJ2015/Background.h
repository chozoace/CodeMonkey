#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

class Background : public GameObject
{
	public:
		Background();
		Background(std::string imagePath);
};

#endif BACKGROUND_H