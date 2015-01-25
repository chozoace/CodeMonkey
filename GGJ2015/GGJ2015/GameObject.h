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
//#include "Command.h"

class Command;
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

		int getId(){ return id; }
		void moveWall(int direction);
		bool isPushable() { return pushable; }
		bool IsWall() { return isWall; }
		int getBlockValue(){ return blockValue; }
		void detectCell();
		void Action(int actionId);
	protected:
		Visibility* _v;
		Tickable* _t;
		Command* leftCommand;
		Command* rightCommand;
		Command* downCommand;
		Command* upCommand;
		bool pushable = false;
		bool isWall = false;
		float _xPosition = 0;
		float _yPosition = 0;
		int _width = 0;
		int _height = 0;
		int id = 0; //player id = 100
		
		int blockValue = 0;
};

#endif GAMEOBJECT_H