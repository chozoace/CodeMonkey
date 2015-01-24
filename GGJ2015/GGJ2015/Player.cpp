#include "Player.h"
#include "Visible.h"
#include "GameController.h"

Player* Player::instance;

Player* Player::Instance()
{
	return instance;
}

Player::Player() : GameObject(new Visible(this), new Tickable(this))
{
	//load image
	//
	GameController::Instance()->addToGameObjectList(this);
}