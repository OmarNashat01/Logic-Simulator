#pragma once
#include "Action.h"
class Delete :public Action
{
public:
	Delete(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo(Component*&);
};

