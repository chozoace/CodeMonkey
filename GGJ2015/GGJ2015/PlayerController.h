#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Tickable.h"
#include "Player.h"
#include "Command.h"

class PlayerController : public Tickable
{
	public:
		PlayerController(Player* playerRef);
		virtual ~PlayerController();
		virtual void Update(float timeElapsed);
		void handleInput(SDL_Event& e);
	private:
		Command* leftCommand;
		Command* rightCommand;
		Command* downCommand;
		Command* upCommand;
		enum InputKeys
		{
			RIGHT_KEY = SDLK_d,
			LEFT_KEY = SDLK_a,
			DOWN_KEY = SDLK_s,
			UP_KEY = SDLK_w
		};
};

#endif PLAYERCONTROLLER_H