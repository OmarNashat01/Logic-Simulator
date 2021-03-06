#include "XNOR2.h"


XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(r_GfxInfo, 2, r_FanOut)
{
	m_CompType = COMP_XNOR2;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XNOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
	m_OutputPin.setStatus((m_InputPins[0].getStatus() == m_InputPins[1].getStatus()) ? HIGH : LOW);

}

// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo, this->getName(), IsSelected);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

