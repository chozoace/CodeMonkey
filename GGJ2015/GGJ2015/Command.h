#ifndef COMMAND_H
#define COMMAND_H

#include "Player.h"
#include "GameObject.h"

class Command
{
	public:
		virtual void Execute(GameObject* theObject) {}
		virtual void ExecuteRelease(GameObject* theObject) {}
};

class RightCommand : public Command
{
	public:
		void Execute(GameObject* theObject) { rightMove(theObject); }
		void ExecuteRelease(GameObject* theObject) { rightMoveRelease(theObject); }
	private:
		void rightMove(GameObject* theObject);
		void rightMoveRelease(GameObject* theObject);
		bool movingRight = false;
};

class LeftCommand : public Command
{
	public:
		void Execute(GameObject* theObject) { leftMove(theObject); }
		void ExecuteRelease(GameObject* theObject) { leftMoveRelease(theObject); }
	private:
		void leftMove(GameObject* theObject);
		void leftMoveRelease(GameObject* theObject);
		bool movingLeft = false;
};

class UpCommand : public Command
{
	public:
		void Execute(GameObject* theObject) { upMove(theObject); }
		void ExecuteRelease(GameObject* theObject) { upMoveRelease(theObject); }
	private:
		void upMove(GameObject* theObject);
		void upMoveRelease(GameObject* theObject);
		bool movingUp = false;
};

class DownCommand : public Command
{
	public:
		void Execute(GameObject* theObject) { downMove(theObject); }
		void ExecuteRelease(GameObject* theObject) { downMoveRelease(theObject); }
	private:
		void downMove(GameObject* theObject);
		void downMoveRelease(GameObject* theObject);
		bool movingDown = false;
};

#endif COMMAND_H