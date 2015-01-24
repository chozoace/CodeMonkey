#ifndef COMPONENT_H
#define COMPONENT_H

using namespace std;
#include <string>
//#include "GameObject.h"
class GameObject;

class Component
{
	public:
		Component();
		virtual ~Component();
		virtual void Update();
		virtual void Destroy();
		string GetComponentName();
		Component* GetComponent();
	protected:
		GameObject* myObject;
		string componentName;
};

#endif COMPONENT_H