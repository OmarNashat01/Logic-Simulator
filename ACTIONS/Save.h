#pragma once
#include<fstream>
#include "Action.h"
#include"..\ApplicationManager.h"

class Save : public Action
{

public:
	Save(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	void ReadActionParameters();

	//Execute action (code depends on action type)
	void Execute();

	//To undo this action (code depends on action type)
	void Undo();

	//To redo this action (code depends on action type)
	void Redo(Component*&);
};

