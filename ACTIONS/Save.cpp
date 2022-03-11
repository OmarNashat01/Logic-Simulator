#include "Save.h"

Save::Save(ApplicationManager* pApp) : Action(pApp)
{
}

void Save::ReadActionParameters()
{}

void Save::Execute()
{
	ofstream file("SavedCircuit.txt", ios::out);
	if (!file.is_open()) { pManager->GetOutput()->PrintMsg("Failed to open the file..."); return; }
	{int count = 0;
	for (int i = 0; i < pManager->CompCount; i++)
	{
		Gate* gateptr = dynamic_cast<Gate*>(pManager->CompList[i]);
		if (gateptr) { count++; }
	}
	file << count << std::endl;
	}
	for (int i = 0; i < pManager->CompCount; i++)
	{
		Gate* gateptr = dynamic_cast<Gate*>(pManager->CompList[i]);
		if (gateptr)
		{
			string real_name = gateptr->getName();
			if (real_name == "")
				real_name = "$";
			file << i + 1 << "\t" << gateptr->GetCompType() << "\t" << real_name << "\t" << gateptr->GetGraphicsInfo().x1 << "\t" << gateptr->GetGraphicsInfo().y1 << std::endl;
		}
	}
	file << "Connections\n";
	for (int i = 0; i < pManager->CompCount; i++)
	{
		int idsrc = -1, iddst = -1, numofdstpin = -1;
		Connection* conptr = dynamic_cast<Connection*>(pManager->CompList[i]);
		if (conptr)
		{
			for (int j = 0; j < pManager->CompCount; j++)
			{
				Gate* gateptr = dynamic_cast<Gate*>(pManager->CompList[j]);
				if (gateptr)
				{
					if (conptr->SrcPin == &gateptr->m_OutputPin) { idsrc = j + 1; continue; }
					for (int k = 0; k < gateptr->m_Inputs; k++)
					{
						if (conptr->DstPin == &gateptr->m_InputPins[k]) { iddst = j+1; numofdstpin = k; break; }
					}
				}
			}
			file << i + 1 << "\t" << idsrc << "\t" << iddst << "\t" << numofdstpin << std::endl;
		}
	}
	file << -1;
	file.close();
	delete this;
}

void Save::Undo()
{}

void Save::Redo(Component*&)
{}
