#ifndef KNOWWHATTODONODE_H
#define KNOWWHATTODONODE_H

#include "ConditionNode.h"

namespace BT
{
    class KnowWhatToDoNode : public ConditionNode
    {
        using ConditionNode::ConditionNode;
    public:
        // Constructor
        KnowWhatToDoNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
