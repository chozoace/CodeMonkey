#include "Player.h"
#include "Visible.h"
#include "GameController.h"

Player* Player::instance;

Player* Player::Instance()
{
	return instance;
}

Player::Player(int xPos, int yPos)
{
	//load image
	//
	_v = new Visible(this);
	playerController = new PlayerController(this);
	_xPosition = xPos;
	_yPosition = yPos;
	_width = 64;
	_height = 64;
	_v->setTexture(GameController::Instance()->loadTexture("Player.png"));
	instance = this;
	GameController::Instance()->addToGameObjectList(this);
}

void Player::Update(float timeElapsed)
{
	playerController->Update(timeElapsed);
}

Player::~Player()
{
	instance = NULL;
}

PlayerController* Player::getPlayerController()
{
	return playerController;
}
