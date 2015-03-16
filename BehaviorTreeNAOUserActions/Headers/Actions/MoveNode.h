#ifndef MOVENODE_H
#define MOVENODE_H

#include "ActionNode.h"

namespace BT
{
    class MoveNode : public ActionNode
    {
        using ActionNode::ActionNode;
    public:
        // Constructor
        MoveNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method used to interrupt the execution of the node
        bool Halt();
    };
}

#endif
