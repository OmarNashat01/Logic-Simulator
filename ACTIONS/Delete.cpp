#include "Delete.h"
#include"..\ApplicationManager.h"
Delete::Delete(ApplicationManager* pApp): Action(pApp)
{}

void Delete::ReadActionParameters()
{
}

void Delete::Execute()
{
	int x, y;
	pManager->OutputInterface->PrintMsg("Please Click on the component you wish to delete");
	pManager->InputInterface->GetPointClicked(x, y);
	Gate* gateptr = pManager->LocateGate(x, y);
	Connection* connptr;
	if (gateptr)
	{
		for (int c1 = 0; c1 < 2; c1++) //To solve the problem of not deleting the last connection
		{
			for (int i = 0; i < pManager->CompCount; i++)
			{
				connptr = dynamic_cast<Connection*>(pManager->CompList[i]);
				if (connptr)
				{
					for (int k = 0; k < gateptr->GetNumOfInputs() ; k++)
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
		for (int i = 0; i < pManager->CompCount; i++)
		{
			if (gateptr == pManager->CompList[i])
			{
				delete gateptr;
				for (int j = i; j < pManager->CompCount - 1; j++)
				{
					pManager->CompList[j] = pManager->CompList[j + 1];
				}
				pManager->CompCount--;
				break;
			}
		}
		pManager->OutputInterface->PrintMsg("Component deleted..");
		delete this;
		return;
	}
	else
	{
		connptr = dynamic_cast<Connection*>(pManager->LocateComp(x, y));
		if (connptr)
		{
			for (int i = 0; i < pManager->CompCount; i++)
			{
				if (pManager->CompList[i] == connptr)
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
			pManager->OutputInterface->PrintMsg("Component deleted..");
			delete this;
			return;
		}
	}
	pManager->OutputInterface->PrintMsg("No Component was detected..");
	delete this;
}

void Delete::Undo()
{
}

void Delete::Redo(Component*&)
{
}
