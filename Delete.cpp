#include "Delete.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp) {}

void Delete::Execute()
{
    ApplicationManager* pM = pManager;
    Output* pOut = pM->GetOutput();

    // Case 1: Multiple selection
    if (pM->GetSelectedCount() > 0)
    {
        pM->DeleteSelected();
        pOut->PrintMsg("Deleted multiple selected components.");
    }
    // Case 2: Single selection
    else if (pM->GetSelectedComponent())
    {
        Component* sel = pM->GetSelectedComponent();
        pM->RemoveComponent(sel);
        pM->ClearSelection();
        pOut->PrintMsg("Deleted selected component.");
       
    }
    else
    {
        pOut->PrintMsg("No component selected to delete.");
        return;
    }
    // Redraw
    pM->UpdateInterface();
    pOut->ClearDrawingArea();
   
   
}
