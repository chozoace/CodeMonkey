#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <Windows.h>
#include "Visibility.h"
#include "Tickable.h"

class GameObject
{
	public:
		GameObject();
		GameObject(Visibility* v, Tickable* t);
		~GameObject();
		virtual void Update(float timeElapsed);
		void Draw(SDL_Renderer* theRenderer);
		SDL_Rect GetDestRect()
		{
			SDL_Rect result;
			result.x = (int)_xPosition;
			result.y = (int)_yPosition;
			result.w = _width;
			result.h = _height;
			return result;
		}
		void setXPos(float newPos){ _xPosition = newPos; }
		void setYPos(float newPos){ _yPosition = newPos; }
		float getXPos(){ return _xPosition; }
		float getYPos(){ return _yPosition; }
		int getWidth(){ return _width; }
		int getHeight(){ return _height; }
		Tickable* getTickableComponent(){ return _t; }
	protected:
		Visibility* _v;
		Tickable* _t;
		float _xPosition = 0;
		float _yPosition = 0;
		int _width = 0;
		int _height = 0;
};

#endif GAMEOBJECT_H