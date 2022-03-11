#include <cstddef>
#ifndef _ACTION_H
#define _ACTION_H

class ApplicationManager; //forward class declaration
class Component;

//Base class for all possible actions (abstract class)
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	bool ReadParameters;
public:
	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor
	
	//Reads parameters required for action to execute
	virtual void ReadActionParameters()=0;
	
	//Execute action (code depends on action type)
	virtual void Execute()=0;

	//To undo this action (code depends on action type)
	virtual void Undo() = 0;

	//To redo this action (code depends on action type)
	virtual void Redo(Component*&)=0;

};

#endif