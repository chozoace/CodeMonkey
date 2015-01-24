#include "Player.h"
#include "Visible.h"
#include "GameController.h"
#include "PlayerController.h"

Player* Player::instance;

Player* Player::Instance()
{
	return instance;
}

Player::Player() : GameObject(new Visible(this), new PlayerController(this))
{
	//load image
	//
	GameController::Instance()->addToGameObjectList(this);
}