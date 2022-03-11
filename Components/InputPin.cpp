#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp, int NumOfPin)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}