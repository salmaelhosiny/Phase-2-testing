#pragma once
#ifndef ADD_LED_ACTION_H
#define ADD_LED_ACTION_H
#include "Actions/Action.h"
#include "Defs.h"

class AddLEDAction : public Action
{
private:
    GraphicsInfo GfxInfo;
public:
    AddLEDAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif