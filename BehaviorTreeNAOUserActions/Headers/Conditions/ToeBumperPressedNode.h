#ifndef TOEBUMPERPRESSEDNODE_H
#define TOEBUMPERPRESSEDNODE_H

#include "ConditionNode.h"

namespace BT
{
    class ToeBumperPressedNode : public ConditionNode
    {
        using ConditionNode::ConditionNode;
    public:
        // Constructor
        ToeBumperPressedNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
