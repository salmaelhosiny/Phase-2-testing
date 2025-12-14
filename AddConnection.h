#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "Action.h"
#include "..\Components\Connection.h"

class AddConnection : public Action
{
private:
    OutputPin* SrcPin;
    InputPin* DstPin;
    int x1, y1, x2, y2;
public:
    AddConnection(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};

#endif
