#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut): Gate(r_GfxInfo, 1 , 0)
{
	m_CompType = COMP_LED;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void LED::Operate()
{
	IsSelected = m_InputPins[0].getStatus();
}

void LED::Draw(Output* pOut)
{
	pOut->DrawLED(m_GfxInfo, this->getName(), IsSelected);
}

int LED::GetOutPinStatus()
{
	return -1;
}

int LED::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}
