#include "Pin.h"

Pin::Pin()
{
	m_Status = LOW;	//Default Status is LOW
}

void Pin::setPos(const GraphicsInfo &Pos)
{
	GInfo = Pos;
}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
}

STATUS Pin::getStatus()
{
	return m_Status;
}

GraphicsInfo Pin::GetPinPos()
{
	return GInfo;
}
