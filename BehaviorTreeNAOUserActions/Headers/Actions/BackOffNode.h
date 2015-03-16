#ifndef BACKOFFNODE_H
#define BACKOFFNODE_H

#include "ActionNode.h"

namespace BT
{
    class BackOffNode : public ActionNode
    {
        using ActionNode::ActionNode;
    public:
        // Constructor
        BackOffNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method used to interrupt the execution of the node
        bool Halt();
    };
}

#endif
