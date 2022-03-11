#include "Cut.h"
#include"..\ApplicationManager.h"
Cut::Cut(ApplicationManager* pApp):Action(pApp)
{}

void Cut::ReadActionParameters()
{}

void Cut::Execute()
{
	int Cx, Cy;
	GraphicsInfo GInfo;
	Connection* connptr;
	pManager->GetOutput()->PrintMsg("Click on the component you want to cut");
	pManager->GetInput()->GetPointClicked(Cx, Cy);
	Gate* gateptr = pManager->LocateGate(Cx, Cy);
	pManager->GetOutput()->PrintMsg("Click on the new position of the component");
	pManager->GetInput()->GetPointClicked(Cx, Cy);
	GInfo.x1 = Cx - UI.GATE_Width / 2;
	GInfo.x2 = Cx + UI.GATE_Width / 2;
	GInfo.y1 = Cy - UI.GATE_Height / 2;
	GInfo.y2 = Cy + UI.GATE_Height / 2;
	gateptr->m_GfxInfo = GInfo;
	for (int c1 = 0; c1 < 2; c1++) //To solve the problem of not deleting the last connection
	{
		for (int i = 0; i < pManager->CompCount; i++)
		{
			connptr = dynamic_cast<Connection*>(pManager->CompList[i]);
			if (connptr)
			{
				for (int k = 0; k < gateptr->GetNumOfInputs(); k++)
				{
					if (connptr->getDestPin() == gateptr->GetInputPin(k))
					{
						delete connptr;
						for (int j = i; j < pManager->CompCount - 1; j++)
						{
							pManager->CompList[j] = pManager->CompList[j + 1];
						}
						pManager->CompCount--;
						break;
					}
				}
				if (connptr->getSourcePin() == gateptr->GetOutputPin())
				{
					delete connptr;
					for (int j = i; j < pManager->CompCount - 1; j++)
					{
						pManager->CompList[j] = pManager->CompList[j + 1];
					}
					pManager->CompCount--;
				}

			}

		}
	}
	delete this;
}

void Cut::Undo()
{}

void Cut::Redo(Component*&)
{}
