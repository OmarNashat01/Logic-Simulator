#include "Edit_Label.h"
#include"..\ApplicationManager.h"
Edit_Label::Edit_Label(ApplicationManager* pApp):Action(pApp)
{}

void Edit_Label::ReadActionParameters()
{}

void Edit_Label::Execute()
{
	int x, y;
	pManager->OutputInterface->PrintMsg("Please Click on the component you wish to edit");
	pManager->InputInterface->GetPointClicked(x, y);
	Gate* gateptr = pManager->LocateGate(x, y);
	if (gateptr)
	{
		pManager->OutputInterface->PrintMsg("Please enter the new label for the component: ");
		gateptr->setSelected();
		pManager->UpdateInterface();
		gateptr->setName(pManager->InputInterface->GetString(pManager->OutputInterface));
		gateptr->setSelected();
	}
	delete this;
}

void Edit_Label::Undo()
{}

void Edit_Label::Redo(Component*&)
{}
