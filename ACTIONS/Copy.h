#pragma once
#include "Action.h"
class Copy :public Action
{
public:
	Copy(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo(Component*&);
};

