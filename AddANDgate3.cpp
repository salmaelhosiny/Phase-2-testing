#include "AddANDgate3.h"
#include "..\ApplicationManager.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddANDgate3::~AddANDgate3(void)
{
}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input
	do {
		pOut->PrintMsg("3-Input AND Gate: Click to add the gate (in the white screen");
		pIn->GetPointClicked(Cx, Cy);
		if (Cy<(UI.ToolBarHeight + UI.AND2_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.AND2_Width / 2)) {
		}
	} while (Cy<(UI.ToolBarHeight + UI.AND2_Width / 2) || Cy >(UI.height - UI.StatusBarHeight - UI.AND2_Width / 2));


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddANDgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND3_Width;
	int Wdth = UI.AND3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	AND3* pA = new AND3(GInfo, AND3_FANOUT);
	pManager->AddComponent(pA);
}

void AddANDgate3::Undo()
{
}

void AddANDgate3::Redo()
{
}



