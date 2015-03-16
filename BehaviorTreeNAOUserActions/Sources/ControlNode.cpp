#include "ControlNode.h"

using namespace BT;

ControlNode::ControlNode(std::string Name) : TreeNode::TreeNode(Name)
{
    Type = Control;
}

void ControlNode::AddChild(TreeNode* Child)
{
    // Checking if the Child is not already present
    for (TreeNode* Node : ChildNodes)
    {
        if (Node == Child)
        {
            throw BehaviorTreeException("'" + Child->Name + "' is already a '" + Name + "' child.");
        }
    }

    ChildNodes.push_back(Child);
    ChildStates.push_back(Idle);
}

unsigned int ControlNode::GetChildrenNumber()
{
    return ChildNodes.size();
}

bool ControlNode::Halt()
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    State = Halted;
    return true;
}

bool ControlNode::WriteState(NodeState StateToBeSet)
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    State = StateToBeSet;
    return true;
}
