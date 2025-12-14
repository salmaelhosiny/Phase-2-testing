#include "AddSwitchAction.h"
#include "ApplicationManager.h"
#include "CSwitch.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

AddSwitchAction::AddSwitchAction(ApplicationManager* pApp) : Action(pApp) {}

void AddSwitchAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMsg("Switch: Click to add a new Switch.");
    pIn->GetPointClicked(GfxInfo.x1, GfxInfo.y1);
    GfxInfo.x2 = GfxInfo.x1 + 50;
    GfxInfo.y2 = GfxInfo.y1 + 50;
    pOut->ClearStatusBar();
}

void AddSwitchAction::Execute()
{
    ReadActionParameters();
    CSwitch* pSw = new CSwitch(GfxInfo);
    pManager->AddComponent(pSw);
}