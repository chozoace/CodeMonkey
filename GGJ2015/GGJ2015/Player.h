#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
#include "GameObject.h"

class Player : public GameObject
{
	public: 
		Player();
		static Player* Instance();
	private:
		static Player* instance;

};

#endif PLAYER_H