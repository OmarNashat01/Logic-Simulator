#pragma once
#include "Action.h"
#include"..\Components\SWITCH.h"
class AddSWITCH : public Action
{
private:
	int Cx, Cy;
	GraphicsInfo GInfo;
	Component* Comp;
public:
	AddSWITCH(ApplicationManager* pApp);
	
	void ReadActionParameters();

	void Execute();

	void Undo();
	void Redo(Component*&);

	~AddSWITCH();
};

