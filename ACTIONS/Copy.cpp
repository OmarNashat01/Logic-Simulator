#include "Copy.h"
#include"..\ApplicationManager.h"
Copy::Copy(ApplicationManager* pApp):Action(pApp)
{}

void Copy::ReadActionParameters()
{}

void Copy::Execute()
{
	int x, y;
	CompType type;
	Gate* gateptr;
	GraphicsInfo comppos;
	pManager->OutputInterface->PrintMsg("Click on the component you want to copy");
	pManager->GetInput()->GetPointClicked(x, y);
	gateptr = pManager->LocateGate(x, y);

	pManager->OutputInterface->PrintMsg("Click on the place you want to place your coppied gate");
	pManager->GetInput()->GetPointClicked(x, y);
	comppos.x1 = x - UI.GATE_Width / 2;
	comppos.x2 = x + UI.GATE_Width / 2;
	comppos.y1 = y - UI.GATE_Height / 2;
	comppos.y2 = y + UI.GATE_Height / 2;
	type = gateptr->GetCompType();
	switch (type)
	{
	case COMP_BUF1:
		pManager->CompList[pManager->CompCount] = new Buffer(comppos, 1);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_NOT1:
		pManager->CompList[pManager->CompCount] = new Not(comppos, 1);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_AND2:
		pManager->CompList[pManager->CompCount] = new AND2(comppos, 2);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_OR2:
		pManager->CompList[pManager->CompCount] = new OR2(comppos, 2);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_NAND2:
		pManager->CompList[pManager->CompCount] = new NAND2(comppos, 2);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_NOR2:
		pManager->CompList[pManager->CompCount] = new NOR2(comppos, 2);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_XOR2:
		pManager->CompList[pManager->CompCount] = new XOR2(comppos, 2);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_XNOR2:
		pManager->CompList[pManager->CompCount] = new XNOR2(comppos, 2);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_AND3:
		pManager->CompList[pManager->CompCount] = new AND3(comppos, 3);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_NOR3:
		pManager->CompList[pManager->CompCount] = new NOR3(comppos, 3);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_XOR3:
		pManager->CompList[pManager->CompCount] = new XOR3(comppos, 3);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_SWITCH:
		pManager->CompList[pManager->CompCount] = new SWITCH(comppos, 1);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	case COMP_LED:
		pManager->CompList[pManager->CompCount] = new LED(comppos, 1);
		pManager->CompList[pManager->CompCount++]->setName(gateptr->getName());
		break;
	}
	delete this;
}

void Copy::Undo()
{}

void Copy::Redo(Component*&)
{}
