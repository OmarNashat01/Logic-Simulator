#ifndef _ADD_OR_GATE_H
#define _ADD_OR_GATE_H

#include "..\Components\OR2.h"
#include"Action.h"


class AddORgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;  //Two corners of the rectangluar area
	Component* Comp;
public:
	AddORgate2(ApplicationManager* pApp);
	virtual ~AddORgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute(void);

	virtual void Undo();
	virtual void Redo(Component*&);
};

#endif