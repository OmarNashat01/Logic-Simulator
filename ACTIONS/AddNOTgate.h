#ifndef _ADD_NOT_GATE_H
#define _ADD_NOT_GATE_H

#include "..\Components\Not.h"
#include"Action.h"


class AddNOTgate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;  //Two corners of the rectangluar area
	Component* Comp;
public:
	AddNOTgate(ApplicationManager* pApp);
	virtual ~AddNOTgate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo(Component*&);
};

#endif