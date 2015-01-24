#include "Camera.h"

Camera* Camera::instance;

Camera::Camera()
{
	_xPosition = 0;
	_yPosition = 0;
	instance = this;
}

Camera::~Camera()
{

}