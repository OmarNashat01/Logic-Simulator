#pragma once
#include "Action.h"
#include"..\Components\LED.h"

class AddLED : public Action
{
private:
	int Cx, Cy;
	GraphicsInfo GInfo;
	Component* Comp;
public: 
	AddLED(ApplicationManager* pApp);
	void ReadActionParameters();

	void Execute();

	void Undo();
	void Redo(Component*&);
	~AddLED();
};

