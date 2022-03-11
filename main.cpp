#include <iostream>
#include <sstream>
#include <cmath>

#include "ApplicationManager.h"

void Phase1()
{
	int x, y;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMsg("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Components with all possible states: Normal, highlighted
	//			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST2: Now we will show that Output class can draw any Component in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GraphicsInfo GfxInfo;  //to be used with draw function of the class Ouput
	pOut->PrintMsg("Simulation tool bar, Click to continue");

	/// 2.1- AND2 Gate test
	pOut->PrintMsg("Drawing 2-input AND gate, Normal and Highlighted,  Click to continue");

	//Drawing Normal AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo);
	

	//Drawing Highlighted AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND2(GfxInfo,"", true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.2- NAND2 Gate test
	pOut->PrintMsg("Drawing 2-input NAND gate, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input NAND gate, Normal and Highlighted
	// Drawing NAND2 gate normal #############################################
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawNAND2(GfxInfo);

	//Drawing NAND2 gate highlighted ########################################
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawNAND2(GfxInfo,"" ,true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.3- OR2 and NOR2 Gates test
	pOut->PrintMsg("Drawing 2-input OR and NOR gates, Normal and Highlighted,  Click to continue");
	///TODO: Add code to draw 2-input OR and NOR gates, Normal and Highlighted for each
	// Drawing 2-input OR gate Normal and Highlighted

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawOR2(GfxInfo);
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawOR2(GfxInfo,"", true);

	//Drawing 2-input NOR gate Normal and Highlighted

	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOR2(GfxInfo);
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOR2(GfxInfo,"", true);


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.4- XOR2 and XNOR2 Gates test
	pOut->PrintMsg("Drawing 2-input XOR and XNOR gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input XOR and XNOR gates, Normal and Highlighted for each

	// Drawing 2-input XOR gate Normal and Highlighted
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawXOR2(GfxInfo);
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawXOR2(GfxInfo,"", true);

	//Drawing 2-input XNOR gate Normal and Highlighted

	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawXNOR2(GfxInfo);
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawXNOR2(GfxInfo,"", true);


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.5- Buffer and Inverter Gates test
	pOut->PrintMsg("Drawing Buffer and Inverter Gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw Buffer and Inverter Gates, Normal and Highlighted for each
	// Drawinng Buffer "BUF1 gate" ###############################################
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawBUF1(GfxInfo);

	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawBUF1(GfxInfo,"", true);

	//Drawing inverter "NOT1 gate"###################################################
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOT1(GfxInfo);

	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOT1(GfxInfo,"", true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.6- AND3, NOR3, and XOR3 Gates test
	pOut->PrintMsg("Drawing 3-input AND, NOR, XOR Gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 3-input AND, NOR, and XOR Gates, Normal and Highlighted for each

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND3(GfxInfo);

	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND3(GfxInfo,"", true);

	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOR3(GfxInfo);

	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOR3(GfxInfo,"", true);

	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawXOR3(GfxInfo);

	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawXOR3(GfxInfo,"", true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.7- Switch and LED test
	pOut->PrintMsg("Drawing Switch and LED, Normal and Highlighted,  Click to continue");

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawLED(GfxInfo);
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawLED(GfxInfo,"", true);
	
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->Drawswitch(GfxInfo);
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->Drawswitch(GfxInfo,"", true);

	///TODO: Add code to draw Switch and LED, Normal and Highlighted for each

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.8- Connections
	pOut->PrintMsg("Drawing connections, Normal, Highlighted, straight, and broken,  Click to continue");
	pOut->PrintMsg("Choose a starting point for your wire");
	pIn->GetPointClicked(x, y);
	GfxInfo.x1 = x;	GfxInfo.y1 = y;
	pOut->PrintMsg("Choose an ending point for your wire");
	pIn->GetPointClicked(x, y);
	GfxInfo.x2 = x;	GfxInfo.y2 = y;
	pOut->DrawConnection(GfxInfo);
	pOut->PrintMsg("Click to show highlited connection");
	pIn->GetPointClicked(x, y);
	pOut->DrawConnection(GfxInfo, true);
	///TODO: Add code to draw connections, Normal, Highlighted, straight, and broken (all combinations) 

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();






	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMsg("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar and print it inside the drawing area
	string in;
	in = pIn->GetString(pOut);
	pOut->PrintMsg("The name you entered is " + in);


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST4: Testing Input ability to detect User Action, click anywhere");
	ActionType ActType;

	///TODO:  You must add a case for each action
	//Add cases for the missing actions below
	//This was the work we did in phase before we knew phase 2 will have different files and classes.

	do
	{
		GraphicsInfo GfxInfo;

		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case OPEN_GATES_MENU:
			pOut->PrintMsg("Action: opening gates menu");
			pOut->CreateGatesToolBar();
			break;
		case ADD_Buff:
			pOut->PrintMsg("Drawing Buffer gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawBUF1(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_INV:
			pOut->PrintMsg("Drawing Inverter gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawNOT1(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_AND_GATE_2:
			pOut->PrintMsg("Drawing 2-input AND gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawAND2(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_OR_GATE_2:
			pOut->PrintMsg("Drawing 2-input OR gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawOR2(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_NAND_GATE_2:
			pOut->PrintMsg("Drawing 2-input NAND gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawNAND2(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_NOR_GATE_2:
			pOut->PrintMsg("Drawing 2-input NOR gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawNOR2(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_XOR_GATE_2:
			pOut->PrintMsg("Drawing 2-input XOR gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawXOR2(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_XNOR_GATE_2:
			pOut->PrintMsg("Drawing 2-input XNOR gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawXNOR2(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_AND_GATE_3:
			pOut->PrintMsg("Drawing 3-input AND gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawAND3(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_NOR_GATE_3:
			pOut->PrintMsg("Drawing 3-input NOR gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			}
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawNOR3(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_XOR_GATE_3:
			pOut->PrintMsg("Drawing 3-input XOR gate,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 40) < UI.ToolBarHeight || (y + 15) > UI.GateMenuStart)
			{
				pOut->PrintMsg("Can't Draw outside the drawing area");
				break;
			};
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawXOR3(GfxInfo);
			pOut->PrintName(pIn, pOut, x, y);
			break;

		case ADD_Switch:
				pOut->PrintMsg("Drawing a Switch,  Click to choose location");
				pIn->GetPointClicked(x, y);
				if (y < UI.ToolBarHeight || y > UI.GateMenuStart)
					break;
				GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
				pOut->Drawswitch(GfxInfo);
				break;

		case ADD_LED:
			pOut->PrintMsg("Drawing LED,  Click to choose location");
			pIn->GetPointClicked(x, y);
			if ((y - 13) < UI.ToolBarHeight || (y + 13) > UI.GateMenuStart)
				break;
			GfxInfo.x1 = x - 25;	GfxInfo.y1 = y - 25;
			pOut->DrawLED(GfxInfo);
			break;

		case ADD_CONNECTION:
			pOut->PrintMsg("Drawing a Connection,  Click to choose starting point");
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight || y > UI.GateMenuStart)
				break;
			GfxInfo.x1 = x;		GfxInfo.y1 = y;
			pOut->PrintMsg("Drawing a Connection,  Click to choose ending point");
			pIn->GetPointClicked(x, y);
			if (y < UI.ToolBarHeight || y > UI.GateMenuStart)
				break;
			GfxInfo.x2 = x;		GfxInfo.y2 = y;

			pOut->DrawConnection(GfxInfo);
			break;

		case SELECT:
			pOut->PrintMsg("Action: a click on the Drawing area, Click anywhere");
			break;

		case STATUS_BAR:
			pOut->PrintMsg("Action: a click on the Status Bar, Click anywhere");
			break;

		case DSN_TOOL:
			pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case SIM_MODE:
			pOut->PrintMsg("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar();
			break;

		case DSN_MODE:
			pOut->PrintMsg("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CreateDesignToolBar();
			break;


		case EXIT:
			break;
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMsg("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
}



int main()
{
	//Phase 1 is displayed in this funciton for ease of use and to differentiate between it and phase 2.
	//Uncomment to test phase 1.
	//Phase1(); 

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action 
		AppManager.ExecuteAction(ActType);

		//Update the drawing window
		AppManager.UpdateInterface();
	

	}while(ActType != EXIT);
		
	return 0;
}

