#ifndef ISSTANDUPNODE_H
#define ISSTANDUPNODE_H

#include "ConditionNode.h"

namespace BT
{
    class IsStandUpNode : public ConditionNode
    {
        using ConditionNode::ConditionNode;
    public:
        // Constructor
        IsStandUpNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
