#ifndef CROUCHNHODE_H
#define CROUCHNHODE_H

#include "ActionNode.h"

namespace BT
{
    class CrouchNode : public ActionNode
    {
        using ActionNode::ActionNode;
    public:
        // Constructor
        CrouchNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method used to interrupt the execution of the node
        bool Halt();
    };
}

#endif
