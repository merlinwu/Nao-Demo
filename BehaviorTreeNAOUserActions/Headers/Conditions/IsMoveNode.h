#ifndef ISMOVENODE_H
#define ISMOVENODE_H

#include "ConditionNode.h"

namespace BT
{
    class IsMoveNode : public ConditionNode
    {
        using ConditionNode::ConditionNode;
    public:
        // Constructor
        IsMoveNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
