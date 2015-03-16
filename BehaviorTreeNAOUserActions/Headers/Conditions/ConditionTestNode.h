#ifndef CONDITIONTEST_H
#define CONDITIONTEST_H

#include "ConditionNode.h"

namespace BT
{
    class ConditionTestNode : public ConditionNode
    {
        using ConditionNode::ConditionNode;
    public:
        // Constructor
        ConditionTestNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
