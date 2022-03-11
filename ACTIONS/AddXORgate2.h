#ifndef _ADD_XOR_GATE_2_H
#define _ADD_XOR_GATE_2_H

#include "..\Components\XOR2.h"
#include"Action.h"

class AddXORgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;  //Two corners of the rectangluar area
	Component* Comp;
public:
	AddXORgate2(ApplicationManager* pApp);
	virtual ~AddXORgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo(Component*&);
};

#endif
