#include "Visible.h"
#include "GameObject.h"

Visible::Visible(GameObject *theObject)
{
	myObject = theObject;
	componentName = "VisibleComponent";
}

void Visible::Draw(SDL_Renderer* theRenderer)
{
	destRect = myObject->GetDestRect();
	//printf("drawing at x = %d\n", myObject->getXPos());
	SDL_RenderCopy(theRenderer, myTexture, NULL, &destRect);
	//SDL_RenderCopy(theRenderer, myTexture, NULL, NULL);
}

/*void Visible::Draw(SDL_Renderer* theRenderer, )
{
	destRect = myObject->GetDestRect();
	//printf("drawing at x = %d\n", myObject->getXPos());
	SDL_RenderCopy(theRenderer, myTexture, NULL, &destRect);
	//SDL_RenderCopy(theRenderer, myTexture, NULL, NULL);
}*/