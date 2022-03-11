#pragma once
#include "Action.h"
class Edit_Label : public Action
{
public:
	Edit_Label(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo(Component*&);
};

