#include "AddBufferGate.h"
#include "..\ApplicationManager.h"

AddBufferGate::AddBufferGate(ApplicationManager* pApp) : Action(pApp)
{
	Cx = -100; Cy = -100;
	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;
}

AddBufferGate::~AddBufferGate(void)
{
}

void AddBufferGate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input Buffer Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	Gate* gateptr = pManager->LocateGate(Cx, Cy, true);

	if (Cy < UI.ToolBarHeight + 25|| Cy > UI.GateMenuStart -25|| gateptr)
		ReadParameters = false;

	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBufferGate::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Center point of the Gate
	ReadActionParameters();

	if (ReadParameters)
	{
		Comp = new Buffer(GInfo, AND2_FANOUT);
		pOut->DrawBUF1(GInfo);
		string name = pIn->GetString(pOut);
		Comp->setName(name);
		pManager->AddComponent(Comp);
		pManager->AddAction(this);
	}
	else
		pOut->PrintMsg("Invalid position");
}

void AddBufferGate::Undo()
{
	delete Comp;
	Comp = NULL;
}

void AddBufferGate::Redo(Component*& ptr)
{
	Comp = new Buffer(GInfo, AND2_FANOUT);
	ptr = Comp;
}



