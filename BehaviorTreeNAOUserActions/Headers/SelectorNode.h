#ifndef SELECTORNODE_H
#define SELECTORNODE_H

#include "ControlNode.h"

namespace BT
{
    class SelectorNode : public ControlNode
    {
        using ControlNode::ControlNode;
    public:
        // Constructor
        SelectorNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
