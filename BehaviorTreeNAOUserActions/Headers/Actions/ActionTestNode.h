#ifndef ACTIONTEST_H
#define ACTIONTEST_H

#include "ActionNode.h"

namespace BT
{
    class ActionTestNode : public ActionNode
    {
        using ActionNode::ActionNode;
    public:
        // Constructor
        ActionTestNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method used to interrupt the execution of the node
        bool Halt();
    };
}

#endif
