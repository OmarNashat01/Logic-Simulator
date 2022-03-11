#include "Load.h"

Load::Load(ApplicationManager* pApp): Action(pApp)
{}

void Load::ReadActionParameters()
{}

void Load::Execute()
{
	int x, y;
	pManager->GetOutput()->PrintMsg("Add file name to be loaded or else press Escape and the default file will load..");
	pManager->GetInput()->GetPointClicked(x, y);
	pManager->GetOutput()->PrintMsg("Enter file name wihtout the extension.");
	pManager->GetInput()->GetPointClicked(x, y);
	string filename = pManager->GetInput()->GetString(pManager->GetOutput());
	if (filename == "") { filename = "SavedCircuit.txt"; }
	else { filename = filename + ".txt"; }
	fstream file;
	file.open((filename.c_str()));
	if (!file.is_open()) { pManager->GetOutput()->PrintMsg("Failed to open the file..."); return; }
	{string label;
	int comptype;
	int i, x, y, CompCount;
	GraphicsInfo comppos;
	file >> CompCount;
	for (int j = 0; j < CompCount; j++)
	{
		file >> i;
		file >> comptype; file >> label;
		if (label == "$") { label = ""; }
		file >> x; file >> y;
		comppos.x1 = x; comppos.y1 = y; comppos.x2 = x + UI.GATE_Width; comppos.y2 = y + UI.GATE_Height;
		switch (comptype)
		{
		case COMP_BUF1:
			pManager->CompList[i - 1] = new Buffer(comppos, 1);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_NOT1:
			pManager->CompList[i - 1] = new Not(comppos, 1);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_AND2:
			pManager->CompList[i - 1] = new AND2(comppos, 2);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_OR2:
			pManager->CompList[i - 1] = new OR2(comppos, 2);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_NAND2:
			pManager->CompList[i - 1] = new NAND2(comppos, 2);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_NOR2:
			pManager->CompList[i - 1] = new NOR2(comppos, 2);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_XOR2:
			pManager->CompList[i - 1] = new XOR2(comppos, 2);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_XNOR2:
			pManager->CompList[i - 1] = new XNOR2(comppos, 2);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_AND3:
			pManager->CompList[i - 1] = new AND3(comppos, 3);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_NOR3:
			pManager->CompList[i - 1] = new NOR3(comppos, 3);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_XOR3:
			pManager->CompList[i - 1] = new XOR3(comppos, 3);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_SWITCH:
			pManager->CompList[i - 1] = new SWITCH(comppos, 1);
			pManager->CompList[i - 1]->setName(label);
			break;
		case COMP_LED:
			pManager->CompList[i - 1] = new LED(comppos, 1);
			pManager->CompList[i - 1]->setName(label);
			break;
		}
	}
	file >> label;
	pManager->CompCount = CompCount;
	}
	int i, idsrc, iddst, numofpin, count = 0;
	GraphicsInfo pos;
	Gate* srcgate, * dstgate;
	while (file >> i)
	{
		if (i == -1) { break; }
		file >> idsrc >> iddst >> numofpin;
		idsrc--; iddst--;
		srcgate = dynamic_cast<Gate*>(pManager->CompList[idsrc]);
		dstgate = dynamic_cast<Gate*>(pManager->CompList[iddst]);

		pos.x1 = srcgate->GetOutputPin()->GetPinPos().x1;
		pos.y1 = srcgate->GetOutputPin()->GetPinPos().y1;
		pos.x2 = dstgate->GetInputPin(numofpin)->GetPinPos().x1;
		pos.y2 = dstgate->GetInputPin(numofpin)->GetPinPos().y1;

		pManager->CompList[i - 1] = new Connection(pos, srcgate->GetOutputPin(), dstgate->GetInputPin(numofpin));
		count++;
	}
	file.close();
	pManager->CompCount += count;
	pManager->UpdateInterface();
	delete this;
}

void Load::Undo()
{
}

void Load::Redo(Component*&)
{
}
