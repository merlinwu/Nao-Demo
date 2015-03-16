#ifndef SETACTIVITYNODE_H
#define SETACTIVITYNODE_H

#include "ActionNode.h"

extern unsigned int Choice;

namespace BT
{
    class SetActivityNode : public ActionNode
    {
        using ActionNode::ActionNode;
    public:
        // Constructor
        SetActivityNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method used to interrupt the execution of the node
        bool Halt();
    };
}

#endif
