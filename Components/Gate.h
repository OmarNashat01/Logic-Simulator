#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	GraphicsInfo* InPinPos, OutPinPos; //The position of the Input and output pins
public:
	Gate(const GraphicsInfo& ,int r_Inputs, int r_FanOut);
	virtual InputPin* GetInputPin(int NumOfPin=0);
	OutputPin* GetOutputPin();

	int GetNumOfInputs();
	friend class Save;
	friend class Cut;
};

#endif
