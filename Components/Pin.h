#ifndef _PIN_H
#define _PIN_H

#include "..\Defs.h"

class Pin
{
protected:
	STATUS m_Status;	//Status of the Pin
	GraphicsInfo GInfo;
public:
	Pin();
	void setPos(const GraphicsInfo&);
	void setStatus(STATUS r_Status);
	STATUS getStatus();
	virtual GraphicsInfo GetPinPos();
};

#endif