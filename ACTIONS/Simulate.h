#pragma once
#include "Action.h"
class Simulate : public Action
{

public:
	Simulate(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo( Component* & ptr);
};

