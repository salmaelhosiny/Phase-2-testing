#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"


//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Component* SelectedArr[MaxCompCount]; // List of selected components for multi-select
	int SelectedCount; // Actual number of selected components

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* ClipboardComp; // Pointer to the component in the clipboard
	Component* SelectedComp;


public:
	// Add a getter for CompList to allow access from other classes
	Component* const* GetCompList() const { return CompList; }
	int GetCompCount() const { return CompCount; }

public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void SaveAll(ofstream& OutputFile);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();





	// selection & clipboard
	void SetSelectedComponent(Component* C);
	Component* GetSelectedComponent() const;
	void ClearSelection();


	//multi-select methods
	void ClearSelections();
	void AddToSelected(Component* C);
	void DeleteSelected();

	
	Component* GetComponentAt(int x, int y) const;
	void RemoveComponent(Component* C);

	void UpdateConnectionsFor(Component* C) const;

	void SetClipboard(Component* C);
	Component* GetClipboard() const;

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void RunSimulation();
	bool ValidateCircuit();
	void CreateTruthTable();
	//destructor
	~ApplicationManager();



	void MoveSelected(int dx, int dy) const;
	int GetSelectedCount() const;
};

#endif