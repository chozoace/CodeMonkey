#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
	public:
		Camera();
		~Camera();
		int getXPosition(){ return _xPosition; }
		int getYPosition(){ return _yPosition; }
		void setXPosition(int value) { _xPosition = value; }
		void setYPosition(int value) { _yPosition = value; }
		static Camera* Instance(){ return instance; }
	private:
		int _xPosition;
		int _yPosition;
		static Camera* instance;
};

#endif CAMERA_H
