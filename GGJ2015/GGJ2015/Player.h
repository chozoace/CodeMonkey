#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
#include "GameObject.h"
#include "PlayerController.h"

class Player : public GameObject
{
	public: 
		Player(int xPos, int yPos);
		virtual ~Player();
		static Player* Instance();
		virtual void Update(float timeElapsed);
		PlayerController* getPlayerController();
	private:
		static Player* instance;
		PlayerController* playerController;
};

#endif PLAYER_H