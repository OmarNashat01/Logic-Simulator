#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(const GraphicsInfo& r_GfxInfo, int r_Inputs, int r_FanOut):Component(r_GfxInfo),m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	InPinPos = new GraphicsInfo[m_Inputs];

	//Setting the position of the pins with some allowance..
	GraphicsInfo temp;
	if (r_FanOut != 0 )
	{
		if (m_Inputs == 1)
		{
			temp.x1 = m_GfxInfo.x1 ;
			temp.x2 = m_GfxInfo.x1 + 6;
			temp.y1 = m_GfxInfo.y1 + 25;
			temp.y2 = m_GfxInfo.y1 + 30;
			m_InputPins[0].setPos(temp);
		}
		else if (m_Inputs == 2)
		{
			temp.x1 = m_GfxInfo.x1 ;
			temp.x2 = m_GfxInfo.x1 + 6;
			temp.y1 = m_GfxInfo.y1 + 13;
			temp.y2 = m_GfxInfo.y1 + 18;
			m_InputPins[0].setPos(temp);

			temp.x1 = m_GfxInfo.x1 ;
			temp.x2 = m_GfxInfo.x1 + 6;
			temp.y1 = m_GfxInfo.y1 + 36;
			temp.y2 = m_GfxInfo.y1 + 41;
			m_InputPins[1].setPos(temp);
		}
		else if (m_Inputs == 3)
		{
			temp.x1 = m_GfxInfo.x1 ;
			temp.x2 = m_GfxInfo.x1 + 6;
			temp.y1 = m_GfxInfo.y1 + 11;
			temp.y2 = m_GfxInfo.y1 + 16;
			m_InputPins[0].setPos(temp);

			temp.x1 = m_GfxInfo.x1 ;
			temp.x2 = m_GfxInfo.x1 + 6;
			temp.y1 = m_GfxInfo.y1 + 24;
			temp.y2 = m_GfxInfo.y1 + 29;
			m_InputPins[1].setPos(temp);

			temp.x1 = m_GfxInfo.x1 ;
			temp.x2 = m_GfxInfo.x1 + 6;
			temp.y1 = m_GfxInfo.y1 + 38;
			temp.y2 = m_GfxInfo.y1 + 43;
			m_InputPins[2].setPos(temp);
		}

		temp.x1 = m_GfxInfo.x1 + 44;
		temp.x2 = m_GfxInfo.x1 + 50;
		temp.y1 = m_GfxInfo.y1 + 24;
		temp.y2 = m_GfxInfo.y1 + 29;
		m_OutputPin.setPos(temp);
	}
	else
	{
		temp.x1 = m_GfxInfo.x1 + 9;
		temp.x2 = m_GfxInfo.x1 + 16;
		temp.y1 = m_GfxInfo.y1 + 25;
		temp.y2 = m_GfxInfo.y1 + 31;
		m_InputPins[0].setPos(temp);
	}

	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this, i);
}

InputPin* Gate::GetInputPin(int NumOfPin)
{
	return &m_InputPins[NumOfPin];
}

OutputPin* Gate::GetOutputPin()
{
	return &m_OutputPin;
}

int Gate::GetNumOfInputs()
{
	return m_Inputs;
}
