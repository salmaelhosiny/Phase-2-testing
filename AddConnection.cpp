#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

AddConnection::AddConnection(ApplicationManager* pApp) : Action(pApp), SrcPin(nullptr), DstPin(nullptr) {}

void AddConnection::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click on the source component's output area");
    pIn->GetPointClicked(x1, y1);
    Component* c1 = pManager->GetComponentAt(x1, y1);
    if (!c1) { pOut->PrintMsg("No component at that position"); return; }

    SrcPin = c1->GetOutputPin();
    if (!SrcPin) { pOut->PrintMsg("Selected component has no output pin"); SrcPin = nullptr; return; }

    pOut->PrintMsg("Click on the destination component's input area");
    pIn->GetPointClicked(x2, y2);
    Component* c2 = pManager->GetComponentAt(x2, y2);
    if (!c2) { pOut->PrintMsg("No component at that position"); SrcPin = nullptr; return; }

    DstPin = c2->GetFreeInputPin();
    if (!DstPin) { pOut->PrintMsg("No free input pin on selected component"); SrcPin = nullptr; DstPin = nullptr; return; }

    pOut->ClearStatusBar();
}

void AddConnection::Execute()
{
    ReadActionParameters();
    if (!SrcPin || !DstPin) return;

    GraphicsInfo g; g.x1 = x1; g.y1 = y1; g.x2 = x2; g.y2 = y2;
    Connection* pConn = new Connection(g, SrcPin, DstPin);
    if (!SrcPin->ConnectTo(pConn)) { delete pConn; return; }
    DstPin->setConnection(pConn);
    pManager->AddComponent(pConn);
}
