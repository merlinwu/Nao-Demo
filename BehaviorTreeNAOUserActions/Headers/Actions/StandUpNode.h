#ifndef STANDUPNODE_H
#define STANDUPNODE_H

#include "ActionNode.h"

namespace BT
{
    class StandUpNode : public ActionNode
    {
        using ActionNode::ActionNode;
    public:
        // Constructor
        StandUpNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method used to interrupt the execution of the node
        bool Halt();
    };
}

#endif
