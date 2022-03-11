#include "AddSWITCH.h"
#include"..\ApplicationManager.h"
AddSWITCH::AddSWITCH(ApplicationManager* pApp): Action(pApp)
{
	Cx = -100; Cy = -100;
	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;
}

AddSWITCH::~AddSWITCH()
{
	if (Comp)
		delete Comp;
}
void AddSWITCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to add a Switch");

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

void AddSWITCH::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (ReadParameters)
	{
		Comp = new SWITCH(GInfo, AND2_FANOUT);
		pOut->Drawswitch(GInfo);
		string name = pIn->GetString(pOut);
		Comp->setName(name);
		pManager->AddComponent(Comp);
		pManager->AddAction(this);
	}
	else
		pOut->PrintMsg("Invalid position");
}

void AddSWITCH::Undo()
{
	delete Comp;
	Comp = NULL;
}

void AddSWITCH::Redo(Component*& ptr)
{
	Comp = new SWITCH(GInfo, AND2_FANOUT);
	ptr = Comp;
}
