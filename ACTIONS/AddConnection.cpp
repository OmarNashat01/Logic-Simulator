#include "AddConnection.h"
#include"..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp): Action(pApp)
{
	ReadParameters = false;
	GInfo.x1 = -100;
	GInfo.x2 = -100;
	GInfo.y1 = -100;
	GInfo.y2 = -100;
}

AddConnection::~AddConnection(void)
{
	if (Comp)
		delete Comp;
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	pManager->ShowPins();
	//Print Action Message
	pOut->PrintMsg("Adding a connection: Click on the source pin");
	
	pIn->GetPointClicked(x,y);
	if (y <= UI.ToolBarHeight || y > UI.GateMenuStart)
	{
		pOut->ClearStatusBar();
		return;
	}
	Gate *srcgate = pManager->LocateGate(x, y);
	
	while (!srcgate)
	{
		pOut->PrintMsg("Wrong click try again..");
		pIn->GetPointClicked(x, y);
		if (y <= UI.ToolBarHeight || y > UI.GateMenuStart)
		{
			pOut->ClearStatusBar();
			return;
		}
		srcgate = pManager->LocateGate(x, y);
	}
	srcpin = srcgate->GetOutputPin();
	pOut->PrintMsg("Adding a connection: Click on your destination pin");

	pIn->GetPointClicked(x,y);
	if (y <= UI.ToolBarHeight || y > UI.GateMenuStart)
	{
		pOut->ClearStatusBar();
		return;
	}
	dstpin = pManager->LocateInPin(x, y);

	while (!dstpin)
	{
		pOut->PrintMsg("Wrong click try again..");
		pIn->GetPointClicked(x, y);
		if (y <= UI.ToolBarHeight || y > UI.GateMenuStart)
		{
			pOut->ClearStatusBar();
			return;
		}
		dstpin = pManager->LocateInPin(x, y);
	}

	//Setting the Graphics info of the Connection
	GInfo.x1 = srcpin->GetPinPos().x1;
	GInfo.y1 = srcpin->GetPinPos().y1;
	GInfo.x2 = dstpin->GetPinPos().x1;
	GInfo.y2 = dstpin->GetPinPos().y1;

	pOut->ClearStatusBar();
	ReadParameters = true;
}

void AddConnection::Execute()
{
	ReadActionParameters();
	if (ReadParameters)
	{
		Comp = new Connection(GInfo, srcpin, dstpin);
		pManager->AddComponent(Comp);
		pManager->AddAction(this);
	}
}

void AddConnection::Undo()
{
	delete Comp;
	Comp = NULL;
}

void AddConnection::Redo(Component*& ptr)
{
	Comp = new Connection(GInfo, srcpin, dstpin);
	ptr = Comp;
}
