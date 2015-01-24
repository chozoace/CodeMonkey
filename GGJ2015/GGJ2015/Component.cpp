#include "Component.h"

Component::Component()
{
	componentName = "defaultComponent";
}

Component::~Component()
{
	myObject = NULL;
}

void Component::Update()
{

}

void Component::Destroy()
{

}

string Component::GetComponentName()
{
	return componentName;
}

Component* Component::GetComponent()
{
	return this;
}