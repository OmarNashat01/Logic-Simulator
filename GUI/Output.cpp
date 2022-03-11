#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
void Output::PrintName(Input* in,Output *out, int x, int y) const
{
	out->PrintMsg("Enter the name of the gate: ");
	string name = in->GetString(out);
	pWind->SetFont(15, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->DrawString(x - 25, y - 40, name);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight+2, UI.width, UI.height - UI.StatusBarHeight - UI.MenuBarHeight-2);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_ADDGATE] = "images\\Menu\\ADD.jpg";
	MenuItemImages[ITM_ADDLED] = "images\\Menu\\LED_OFF.jpg";
	MenuItemImages[ITM_ADDSWITCH] = "images\\Menu\\SWITCH_OFF.jpg";
	MenuItemImages[ITM_ADDCONNECTION] = "Images\\Menu\\WIRE.jpg";
	MenuItemImages[ITM_COPY] = "Images\\Menu\\COPY.jpg";
	MenuItemImages[ITM_CUT] = "Images\\Menu\\CUT.jpg";
	MenuItemImages[ITM_DELETE] = "Images\\Menu\\DELETE.jpg";
	MenuItemImages[ITM_EDIT] = "Images\\Menu\\EDIT.jpg";
	MenuItemImages[ITM_LOAD] = "Images\\Menu\\LOAD.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\UNDO.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\REDO.jpg";
	MenuItemImages[ITM_SIMMODE] = "images\\Menu\\SIM.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	pWind->SetPen(BLACK, 3);
	for (int i = 0; i < ITM_DSN_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		pWind->DrawLine(i * UI.ToolItemWidth, 0, i * UI.ToolItemWidth, 80);
	}
	//Draw a line under the toolbar

	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output::CreateGatesToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_GATE_CNT];

	MenuItemImages[ITM_BUF1] = "images\\Gates\\BUF1.jpg";
	MenuItemImages[ITM_NOT1] = "images\\Gates\\NOT1.jpg";
	MenuItemImages[ITM_AND2] = "images\\Gates\\AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Gates\\OR2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Gates\\NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Gates\\NOR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Gates\\XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Gates\\XNOR2.jpg";
	MenuItemImages[ITM_AND3] = "images\\Gates\\AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Gates\\NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Gates\\XOR3.jpg";


	//TODO: Prepare image for each menu item and add it to the list
	pWind->SetPen(RED, 3);
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_GATE_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuGateWidth , UI.GateMenuStart, UI.MenuGateWidth, UI.MenuBarHeight);
		pWind->DrawLine(i * UI.MenuGateWidth, UI.GateMenuStart, i * UI.MenuGateWidth, UI.height - UI.StatusBarHeight );
	}


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0,UI.GateMenuStart , UI.width, UI.GateMenuStart);

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	pWind->SetPen(WHITE, 3);
	pWind->SetBrush(WHITE);

	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	string SIMItemImages[ITM_SIM_CNT];
	SIMItemImages[ITM_SIM] = "Images\\Menu\\PAUSE.jpg";
	SIMItemImages[ITM_TRUTH] = "Images\\Menu\\SIM.jpg";
	SIMItemImages[ITM_EXIT1]= "Images\\Menu\\EXIT.jpg";

	for (int i = 0; i < ITM_SIM_CNT; i++)
	{
		pWind->DrawImage(SIMItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		pWind->DrawLine(i * UI.ToolItemWidth, 0, i * UI.ToolItemWidth, 80);
	}
	UI.AppMode = SIMULATION;	//Simulation Mode
}
// ####################################################################################################################################
//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//
// drawing AND3 gate#############################
void Output::DrawAND3(GraphicsInfo r_GfxInfo,string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\AND3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
// drawing NOR3 gate#####################################
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\NOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
// drawing XOR3 gate #############################
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\XOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
void Output::DrawAND2(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}

//TODO: Add similar functions to draw all components
// Drawing OR2 gate #################################################################
void Output::DrawOR2(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\OR2.jpg" ;

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
//Drawing NAND2 gate #########################################################
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\NAND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
//Drawing NOR2 gate ###########################################################
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\NOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
//Drawing XOR2 gate #########################################################
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\XOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
// Drawing XNOR2 gate #####################################################
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\XNOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
// Drawing BUF1 gate #####################################################
void Output::DrawBUF1(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\BUF1_Hi.jpg";
	else
		GateImage = "Images\\Gates\\BUF1.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}

// Drawing NOT1 gate #####################################################
void Output::DrawNOT1(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOT1_Hi.jpg";
	else
		GateImage = "Images\\Gates\\NOT1.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
// End of gate drawing
// LED drawing ###############################
void Output::DrawLED(GraphicsInfo r_GfxInfo, string name, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\LED_ON.jpg";
	else
		GateImage = "Images\\Menu\\LED_OFF.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
// switch drawing ################################
void Output::Drawswitch(GraphicsInfo r_GfxInfo, string name, bool selected, bool status) const
{
	string GateImage;
	if (status && !selected)	//use image in the highlighted case
		GateImage = "Images\\Menu\\switch_ON.jpg";
	else if (status && selected)
		GateImage = "Images\\Menu\\switch_ON_HI.jpg";
	else if (!status && selected)
		GateImage = "Images\\Menu\\switch_OFF_HI.jpg";
	else
		GateImage = "Images\\Menu\\switch_OFF.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
	pWind->SetPen(BLACK, 3);
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1 - 17, name);
}
void Output::Showconn(GraphicsInfo r_GfxInfo, int r_Inputs,int nOut) const
{
	string GateImage;
	GateImage = "Images\\Gates\\Red.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	if (nOut == 1)
	{
		if (r_Inputs == 1)
		{
			pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1 + 23, 6, 5);
		}
		else if (r_Inputs == 2)
		{
			pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1 + 11, 6, 5);
			pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1 + 35, 6, 5);
		}
		else if (r_Inputs == 3)
		{
			pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1 + 9, 6, 5);
			pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1 + 22, 6, 5);
			pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1 + 36, 6, 5);
		}
		pWind->DrawImage(GateImage, r_GfxInfo.x1 + 44, r_GfxInfo.y1 + 23, 6, 6);
	}
	else
	{
		pWind->DrawImage(GateImage, r_GfxInfo.x1 + 10, r_GfxInfo.y1+25, 6, 6);
	}
}
// ####################################################################################################################################
void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	if (selected)
		pWind->SetPen(RED, 3);
	else
		pWind->SetPen(BLACK,3);
	int tempx;
	tempx = r_GfxInfo.x1 + (r_GfxInfo.x2 - r_GfxInfo.x1)*9 / 10;

	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, tempx, r_GfxInfo.y1);
	pWind->DrawLine(tempx, r_GfxInfo.y1, tempx, r_GfxInfo.y2);
	pWind->DrawLine(tempx, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);


}


Output::~Output()
{
	delete pWind;
}
