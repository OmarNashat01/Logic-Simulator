#include "SWITCH.h"



SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut): Gate(r_GfxInfo,0,AND2_FANOUT)
{
	m_CompType = COMP_SWITCH;
	sw_status = LOW;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void SWITCH::Operate()
{
	m_OutputPin.setStatus(sw_status);
}

void SWITCH::Draw(Output* pOut)
{
	pOut->Drawswitch(m_GfxInfo, this->getName(), IsSelected, sw_status);
}

int SWITCH::GetOutPinStatus()
{
	return IsSelected;
}

int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{}

void SWITCH::Close_Open()
{
	if (sw_status) { sw_status = LOW; }
	else { sw_status = HIGH; }
}
