#include "Visible.h"
#include "GameObject.h"
#include "Camera.h"

Visible::Visible(GameObject *theObject)
{
	myObject = theObject;
	componentName = "VisibleComponent";
}

void Visible::Draw(SDL_Renderer* theRenderer)
{
	//anything using this draw function must draw relative to the camera
	destRect = myObject->GetDestRect();
	/*int camX = Camera::Instance()->getXPosition();
	int camY = Camera::Instance()->getYPosition();
	destRect.x = destRect.x - camX;
	destRect.y = destRect.y - camY;*/
	SDL_RenderCopy(theRenderer, myTexture, NULL, &destRect);
}