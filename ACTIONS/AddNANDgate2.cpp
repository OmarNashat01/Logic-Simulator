#include "AddNANDgate2.h"
#include "..\ApplicationManager.h"

AddNANDgate2::AddNANDgate2(ApplicationManager* pApp) :Action(pApp)
{
	Cx = -100; Cy = -100;
	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;
}

AddNANDgate2::~AddNANDgate2(void)
{
	if (Comp)
		delete Comp;
}

void AddNANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	Gate* gateptr = pManager->LocateGate(Cx, Cy, true);

	if (Cy < UI.ToolBarHeight +25|| Cy > UI.GateMenuStart -25|| gateptr)
		ReadParameters = false;

	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate2::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (ReadParameters)
	{
		Comp = new NAND2(GInfo, AND2_FANOUT);
		pOut->DrawNAND2(GInfo);
		string name = pIn->GetString(pOut);
		Comp->setName(name);
		pManager->AddComponent(Comp);
		pManager->AddAction(this);
	}
	else
		pOut->PrintMsg("Invalid position");
}

void AddNANDgate2::Undo()
{
	delete Comp;
	Comp = NULL;
}

void AddNANDgate2::Redo(Component*& ptr)
{
	Comp = new NAND2(GInfo, AND2_FANOUT);
	ptr = Comp;
}

