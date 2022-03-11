#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"

AddXNORgate2::AddXNORgate2(ApplicationManager* pApp) :Action(pApp)
{
	Cx = -100; Cy = -100;
	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;
}

AddXNORgate2::~AddXNORgate2(void)
{
	if (Comp)
		delete Comp;
}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	Gate* gateptr = pManager->LocateGate(Cx, Cy, true);

	if (Cy < UI.ToolBarHeight + 25 || Cy > UI.GateMenuStart - 25 || gateptr)
		ReadParameters = false;

	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNORgate2::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (ReadParameters)
	{
		Comp = new XNOR2(GInfo, AND2_FANOUT);
		pOut->DrawXNOR2(GInfo);
		string name = pIn->GetString(pOut);
		Comp->setName(name);
		pManager->AddComponent(Comp);
		pManager->AddAction(this);
	}
	else
		pOut->PrintMsg("Invalid position");
}

void AddXNORgate2::Undo()
{
	delete Comp;
	Comp = NULL;
}

void AddXNORgate2::Redo(Component*& ptr)
{
	Comp = new XNOR2(GInfo, AND2_FANOUT);
	ptr = Comp;
}




