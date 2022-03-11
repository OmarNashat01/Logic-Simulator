#include "AddANDgate3.h"
#include "..\ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) :Action(pApp)
{
	Cx = -100; Cy = -100;
	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;
}

AddANDgate3::~AddANDgate3(void)
{
	if (Comp)
		delete Comp;
}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	Gate* gateptr = pManager->LocateGate(Cx, Cy,true);

	if (Cy < UI.ToolBarHeight + 25 || Cy > UI.GateMenuStart - 25|| gateptr)
		ReadParameters = false;

	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddANDgate3::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Center point of the Gate
	ReadActionParameters();

	if (ReadParameters)
	{
		Comp = new AND3(GInfo, AND2_FANOUT);
		pOut->DrawAND3(GInfo);
		string name = pIn->GetString(pOut);
		Comp->setName(name);
		pManager->AddComponent(Comp);
		pManager->AddAction(this);
	}
	else
		pOut->PrintMsg("Invalid position");
}

void AddANDgate3::Undo()
{
	delete Comp;
	Comp = NULL;
}

void AddANDgate3::Redo(Component*& ptr)
{
	Comp = new AND3(GInfo, AND2_FANOUT);
	ptr = Comp;
}



