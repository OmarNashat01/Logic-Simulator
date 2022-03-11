#pragma once
#include<fstream>
#include "Action.h"
#include"..\ApplicationManager.h"
class Load : public Action
{
public:
	Load(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo(Component*&);
};

