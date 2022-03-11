#include "AddLED.h"
#include"..\ApplicationManager.h"
AddLED::AddLED(ApplicationManager* pApp): Action(pApp)
{
	Cx = -100; Cy = -100;
	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;
}

AddLED::~AddLED()
{
	if (Comp)
		delete Comp;
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to add a LED");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	Gate* gateptr = pManager->LocateGate(Cx, Cy, true);

	if (Cy < UI.ToolBarHeight +25 || Cy > UI.GateMenuStart -25|| gateptr)
		ReadParameters = false;

	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddLED::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (ReadParameters)
	{
		Comp = new LED(GInfo, 0);
		pOut->DrawLED(GInfo);
		string name = pIn->GetString(pOut);
		Comp->setName(name);
		pManager->AddComponent(Comp);
		pManager->AddAction(this);
	}
	else
		pOut->PrintMsg("Invalid position");
}

void AddLED::Undo()
{
	delete Comp;
	Comp = NULL;
}

void AddLED::Redo(Component*& ptr)
{
	Comp = new LED(GInfo, 0);
	ptr = Comp;
}
