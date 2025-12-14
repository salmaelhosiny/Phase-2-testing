#pragma once
#ifndef ADD_SWITCH_ACTION_H
#define ADD_SWITCH_ACTION_H
#include "Actions/Action.h"
#include "Defs.h"

class AddSwitchAction : public Action
{
private:
    GraphicsInfo GfxInfo;
public:
    AddSwitchAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};
#endif