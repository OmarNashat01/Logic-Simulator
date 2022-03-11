#pragma once
#include "Gate.h"
#include"InputPin.h"
class LED :public Gate
{
private:
	GraphicsInfo InPinPos;
public:
	LED(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	void Operate();
	void Draw(Output* pOut);
	int GetOutPinStatus();
	int GetInputPinStatus(int n);
	void setInputPinStatus(int n, STATUS s);
};

