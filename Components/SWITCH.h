#pragma once
#include "Gate.h"
#include"OutputPin.h"
#include"..\Defs.H"

class SWITCH : public Gate
{
private:
	STATUS sw_status;
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	void Operate();
	void Draw(Output* pOut);
	int GetOutPinStatus();
	int GetInputPinStatus(int n);
	void setInputPinStatus(int n, STATUS s);
	void Close_Open();

};

