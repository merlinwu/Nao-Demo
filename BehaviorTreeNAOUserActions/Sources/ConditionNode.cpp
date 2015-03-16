#include "ConditionNode.h"

using namespace BT;

ConditionNode::ConditionNode(std::string Name) : LeafNode::LeafNode(Name)
{
    Type = Condition;
}

bool ConditionNode::Halt() {}

bool ConditionNode::WriteState(NodeState StateToBeSet)
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    State = StateToBeSet;
    return true;
}
