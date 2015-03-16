#ifndef ISCROUCHNODE_H
#define ISCROUCHNODE_H

#include "ConditionNode.h"

namespace BT
{
    class IsCrouchNode : public ConditionNode
    {
        using ConditionNode::ConditionNode;
    public:
        // Constructor
        IsCrouchNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
