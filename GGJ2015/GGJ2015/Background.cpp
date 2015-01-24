#include "Background.h"
#include "Visible.h"
#include "GameController.h"

Background::Background()
{

}

Background::Background(std::string imagePath)
{
	_v = new Visible(this);
	_t = new Tickable(this);
	_v->setTexture(GameController::Instance()->loadTexture(imagePath));
	GameController::Instance()->addToGameObjectList(this);
}