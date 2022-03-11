#include "Simulate.h"
#include"..\ApplicationManager.h"
Simulate::Simulate(ApplicationManager* pApp): Action(pApp)
{}

void Simulate::ReadActionParameters()
{}

void Simulate::Execute()
{
	pManager->GetOutput()->CreateSimulationToolBar();
	for (int i = 0; i < pManager->CompCount; i++)
	{
		for (int i = 0; i < pManager->CompCount; i++)
		{
			pManager->CompList[i]->Operate();
		}
	}
}

void Simulate::Undo()
{}

void Simulate::Redo(Component*& ptr)
{}
