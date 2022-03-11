#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window

}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output *out)
{
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	pWind->FlushKeyQueue();
	out->PrintMsg("Enter a name : ");
	char c = 'f' , word[1000];
	string wordin;
	int i = 0;
	keytype check = ASCII;
	while (c != '\r' && check != ESCAPE)
	{
		check = pWind->WaitKeyPress(c);
		if (check != ESCAPE)
		{
			if (c == '\b')
				i -= 2;
			else
				word[i] = c;
			i++;
			if (i < 0) { i = 0; }
			word[i] = '\0';
			wordin = word;
			out->PrintMsg("Enter a name: " + wordin);
		}
	}

	if (check == ESCAPE)
		return "";
	return wordin.substr(0, wordin.size() - 1);

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADDGATE: return OPEN_GATES_MENU;
			case ITM_ADDLED:  return ADD_LED;
			case ITM_ADDSWITCH: return ADD_Switch;
			case ITM_ADDCONNECTION: return ADD_CONNECTION;
			case ITM_COPY: return COPY;
			case ITM_CUT:  return CUT;
			case ITM_DELETE: return DEL;
			case ITM_EDIT: return EDIT_Label;
			case ITM_LOAD: return LOAD;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SIMMODE: return SIM_MODE;
			case ITM_EXIT: return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.MenuGateHeight - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		if ( y <= UI.height - UI.StatusBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuGateWidth);

			switch (ClickedItemOrder)
			{
			case ITM_BUF1: return ADD_Buff;
			case ITM_NOT1: return ADD_INV;

			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;

			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;

			default: return DSN_TOOL;
			}
		}
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= UI.ToolBarHeight && y < UI.height - UI.MenuGateHeight - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		int ClickedItemOrder = (x / UI.ToolItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_SIM: return DSN_MODE;
	
		}

		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
