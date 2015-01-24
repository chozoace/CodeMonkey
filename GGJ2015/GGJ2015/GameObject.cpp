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
	delete _v;
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