#ifndef SPEAKNODE_H
#define SPEAKNODE_H

#include "ActionNode.h"

namespace BT
{
    class SpeakNode : public ActionNode
    {
        using ActionNode::ActionNode;
    public:
        // Constructor
        SpeakNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method used to interrupt the execution of the node
        bool Halt();
    };
}

#endif
