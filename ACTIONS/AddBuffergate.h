#ifndef _ADD_BUFFER_GATE_H
#define _ADD_BUFFER_GATE_H

#include "..\Components\Buffer.h"
#include"Action.h"


class AddBufferGate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;  //Two corners of the rectangluar area
	Component* Comp;
public:
	AddBufferGate(ApplicationManager* pApp);
	virtual ~AddBufferGate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo(Component*&);
};

#endif
