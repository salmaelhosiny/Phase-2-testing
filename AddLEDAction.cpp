#include "AddLEDAction.h"
#include "ApplicationManager.h"
#include "CLED.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

AddLEDAction::AddLEDAction(ApplicationManager* pApp) : Action(pApp) {}

void AddLEDAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMsg("LED: Click to add a new LED.");
    pIn->GetPointClicked(GfxInfo.x1, GfxInfo.y1);
    GfxInfo.x2 = GfxInfo.x1 + 50;
    GfxInfo.y2 = GfxInfo.y1 + 50;
    pOut->ClearStatusBar();
}

void AddLEDAction::Execute()
{
    ReadActionParameters();
    CLED* pLed = new CLED(GfxInfo);
    pManager->AddComponent(pLed);
}