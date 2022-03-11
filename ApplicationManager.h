#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include<fstream>
#include<string>
#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\AddBuffergate.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddXORgate3.h"
#include"Actions\AddConnection.h"
#include"Actions\Simulate.h"
#include"Actions\AddSWITCH.h"
#include"Actions\AddLED.h"
#include"Actions\Save.h"
#include"Actions\Load.h"
#include"Actions\Delete.h"
#include"Actions\Edit_Label.h"
#include"Actions\Copy.h"
#include"Actions\Cut.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	Action* ActnList[200];
	int actioncount, UnDoneActions;

	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Class Interface
	Input* InputInterface; //pointer to the Input Class Interface

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void AddAction(Action* actn);

	void ShowPins();
	Gate* LocateGate(int x, int y);
	Gate* LocateGate(int x, int y, bool withallowance);

	Component* LocateComp(int x, int y);

	InputPin* LocateInPin(int x, int y);

	//destructor
	~ApplicationManager();

	friend class Simulate;
	friend class Save;
	friend class Load;
	friend class Delete;
	friend class Edit_Label;
	friend class Copy;
	friend class Cut;
};

#endif
