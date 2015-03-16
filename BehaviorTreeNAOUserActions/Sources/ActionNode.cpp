#include "ActionNode.h"

using namespace BT;

ActionNode::ActionNode(std::string Name) : LeafNode::LeafNode(Name)
{
    Type = Action;
}

bool ActionNode::WriteState(NodeState StateToBeSet)
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    // Check for spourios "Halted"
    if (State == Halted && StateToBeSet != Idle)
    {
        return false;
    }

    State = StateToBeSet;
    return true;
}
