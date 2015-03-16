#ifndef CONTROLNODE_H
#define CONTROLNODE_H

#include <vector>

#include "TreeNode.h"

namespace BT
{
    class ControlNode : public TreeNode
    {
        using TreeNode::TreeNode;
    protected:
        // Children vector
        std::vector<TreeNode*> ChildNodes;

        // Children states
        std::vector<NodeState> ChildStates;

        // Vector size
        unsigned int M;
    public:
        // Constructor
        ControlNode(std::string Name);

        // The method used to fill the child vector
        void AddChild(TreeNode* Child);

        // The method used to know the number of children
        unsigned int GetChildrenNumber();

        // The method used to interrupt the execution of the node
        bool Halt();

        // Methods used to access the node state without the
        // conditional waiting (only mutual access)
        bool WriteState(NodeState StateToBeSet);
    };
}

#endif
