#ifndef ADD_CONNECTION_
#define ADD_CONNECTION_
#include"Action.h"
#include"..\Components/Connection.h"
class Gate;

class AddConnection : public Action
{
private:
	GraphicsInfo GInfo;   //The strarting and ending point of the connection
	Component* Comp;
	OutputPin *srcpin;
	InputPin *dstpin;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo(Component*&);
};


#endif