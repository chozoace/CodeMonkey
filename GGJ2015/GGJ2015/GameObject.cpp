#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::GameObject(Visibility* v, Tickable* t)
{
	_v = v;
	_t = t;
}

GameObject::~GameObject()
{
	if (_v != NULL)
		delete _v;
	if (_t != NULL)
		delete _t;
}

void GameObject::Update(float timeElapsed)
{
	_t->Update(timeElapsed);
}

void GameObject::Draw(SDL_Renderer* theRenderer)
{
	_v->Draw(theRenderer);
}