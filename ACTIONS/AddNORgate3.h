#ifndef _ADD_NOR_GATE_3_H
#define _ADD_NOR_GATE_3_H

#include "..\Components\NOR3.h"
#include"Action.h"

class AddNORgate3 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;  //Two corners of the rectangluar area
	Component* Comp;
public:
	AddNORgate3(ApplicationManager* pApp);
	virtual ~AddNORgate3(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute(void);

	virtual void Undo();
	virtual void Redo(Component*&);
};

#endif



