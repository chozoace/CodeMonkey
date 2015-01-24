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
			result.x = _xPosition;
			result.y = _yPosition;
			result.w = _width;
			result.h = _height;
			return result;
		}
		void setXPos(int newPos){ _xPosition = newPos; }
		void setYPos(int newPos){ _yPosition = newPos; }
		int getXPos(){ return _xPosition; }
		int getYPos(){ return _yPosition; }
		int getWidth(){ return _width; }
		int getHeight(){ return _height; }
	protected:
		Visibility* _v;
		Tickable* _t;
		int _xPosition;
		int _yPosition;
		int _width;
		int _height;
};

#endif GAMEOBJECT_H