#include "ApplicationManager.h"


ApplicationManager::ApplicationManager()
{
	CompCount = 0; 
	actioncount = 0; UnDoneActions = 0;
	for (int i = 0; i < MaxCompCount; i++)
	{
		CompList[i] = NULL;
		ActnList[i] = NULL;
	}
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddAction(Action* actn)
{
	ActnList[actioncount++] = actn;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	SWITCH* switchptr;
	int x, y;

	switch (ActType)
	{
	case OPEN_GATES_MENU:
		OutputInterface->PrintMsg("Action: opening gates menu");
		OutputInterface->CreateGatesToolBar();
		break;
	case ADD_Buff:
		pAct = new AddBufferGate(this);
		break;

	case ADD_INV:
		pAct = new AddNOTgate(this);
		break;

	case ADD_AND_GATE_2:
	{
		pAct = new AddANDgate2(this);
		break;
	}

	case ADD_OR_GATE_2:
		pAct = new AddORgate2(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNANDgate2(this);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNORgate2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXORgate2(this);
		break;

	case ADD_XNOR_GATE_2:
		pAct = new AddXNORgate2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddANDgate3(this);
		break;

	case ADD_NOR_GATE_3:
		pAct = new AddNORgate3(this);
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddXORgate3(this);
		break;

	case ADD_Switch:
		pAct = new AddSWITCH(this);
			break;

	case ADD_LED:
		pAct = new AddLED(this);
		break;

	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;
	
	case SELECT:
		OutputInterface->PrintMsg("Action: a click on the Drawing area, Click on the switch to turn on or off");
		InputInterface->GetPointClicked(x, y);
		if (LocateComp(x, y)) {
			switchptr = dynamic_cast<SWITCH*>(LocateComp(x, y));
			if (switchptr) { 
				switchptr->Close_Open();
				pAct = new Simulate(this); 
				OutputInterface->PrintMsg("Change in inputs detected, simulating circuit"); 
			}
		}
		break;

	case STATUS_BAR:
		OutputInterface->PrintMsg("Action: a click on the Status Bar, Click anywhere");
		break;

	case DSN_TOOL:
		OutputInterface->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
		break;

	case SIM_MODE:
		pAct = new Simulate(this);
		break;

	case DSN_MODE:
		OutputInterface->PrintMsg("Action: Switch to Design Mode, creating Design tool bar");
		OutputInterface->CreateDesignToolBar();
		break;

	case UNDO:
		if (actioncount > 0)
		{
			ActnList[--actioncount]->Undo();
			CompCount--;
			UnDoneActions++;
		}
		break;

	case REDO:
		if (UnDoneActions > 0)
		{
			ActnList[actioncount++]->Redo(CompList[CompCount++]);
			UnDoneActions--;
		}
		break;

	case COPY:
		pAct = new Copy(this);
		break;

	case CUT:
		pAct = new Cut(this);
		break;

	case DEL:
		pAct = new Delete(this);
		break;

	case EDIT_Label:
		pAct = new Edit_Label(this);
		break;

	case LOAD:
		pAct = new Load(this);
		break;

	case EXIT:
		OutputInterface->PrintMsg("Exiting the program");
		pAct = new Save(this);
		break;
	}
	if(pAct)
	{
		pAct->Execute();
		UnDoneActions = 0;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Draw(OutputInterface);
	}
}

Gate* ApplicationManager::LocateGate(int x, int y)
{
	GraphicsInfo pos;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gateptr = dynamic_cast<Gate*>(CompList[i]);
		if (gateptr)
		{
			pos = gateptr->GetGraphicsInfo();
			if (pos.x1 < x && pos.x2 > x && pos.y1 < y && pos.y2 > y)
			{
				return gateptr;
			}
		}
	}
	return NULL;
}

Gate* ApplicationManager::LocateGate(int x, int y , bool withallowance)
{
	GraphicsInfo pos;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gateptr = dynamic_cast<Gate*>(CompList[i]);
		if (gateptr)
		{
			pos = gateptr->GetGraphicsInfo();
			if (pos.x1 < x + 25 && pos.x2 > x - 25 && pos.y1 < y + 25 && pos.y2 > y - 25)
			{
				return gateptr;
			}
		}
	}
	return NULL;
}

Component* ApplicationManager::LocateComp(int x, int y)
{
	GraphicsInfo pos;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gateptr = dynamic_cast<Gate*>(CompList[i]);
		Connection* connptr = dynamic_cast<Connection*>(CompList[i]);
		if (gateptr)
		{
			pos = gateptr->GetGraphicsInfo();
			if (pos.x1 < x && pos.x2 > x && pos.y1 < y && pos.y2 > y)    //Check if the point clicked is between the 4 corners of the component
			{
				return gateptr;
			}
		}
		else if(connptr)
		{
			pos = connptr->GetGraphicsInfo();
			if (((y <= pos.y1 + 5 && y >= pos.y1 - 5) && (x > pos.x1 && x < (pos.x1 + (pos.x2 - pos.x1) * 0.9))) ||     // The first horizontal part
				((y <= pos.y2 + 5 && y >= pos.y2 - 5) && (x < pos.x2 && x < (pos.x2 - (pos.x2 - pos.x1) * 0.1))) ||     // The second horizontal part
				( x <= (pos.x1 + (pos.x2 - pos.x1) * 0.9) + 5  && x >= (pos.x1 + (pos.x2 - pos.x1) * 0.9 - 5)))			// The vertical part
				return connptr;	
		}
	}
	return NULL;
}

InputPin* ApplicationManager::LocateInPin(int x, int y)
{
	GraphicsInfo pinpos;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gateptr = dynamic_cast<Gate*>(CompList[i]);
		if (gateptr)
		{
			GraphicsInfo pos = gateptr->GetGraphicsInfo();
			if (pos.x1 < x && pos.x2 > x && pos.y1 < y && pos.y2 > y)
			{
				for (int i = 0; i < gateptr->GetNumOfInputs(); i++)
				{
					pinpos = gateptr->GetInputPin(i)->GetPinPos();
					if (pinpos.x1 - 3 < x && pinpos.x2 + 3 > x && pinpos.y1 - 3 < y && pinpos.y2 + 3 > y)
						return gateptr->GetInputPin(i);
				}
			}
		}
	}
	return NULL;
}


////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	for (int i = 0; i < 200; i++)
	{
		if (ActnList[i])
			delete ActnList[i];
	}
	delete OutputInterface;
	delete InputInterface;
}

void ApplicationManager::ShowPins()
{
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gateptr = dynamic_cast<Gate*>(CompList[i]);
		if (gateptr)
		{
			if (gateptr->GetOutPinStatus() != -1)
				OutputInterface->Showconn(gateptr->GetGraphicsInfo(), gateptr->GetNumOfInputs());
			else
				OutputInterface->Showconn(gateptr->GetGraphicsInfo(), gateptr->GetNumOfInputs(), 0);
		}
	}
}
