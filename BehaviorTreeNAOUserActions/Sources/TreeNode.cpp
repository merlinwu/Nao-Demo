#include "TreeNode.h"

using namespace BT;

TreeNode::TreeNode(std::string Name) : Semaphore(0)
{
    // Name initialization
    this->Name = Name;
}

TreeNode::~TreeNode() {}

NodeState TreeNode::GetNodeState()
{
    NodeState ReadState;
    // Lock acquistion
    std::unique_lock<std::mutex> UniqueLock(StateMutex);

    // Wait until the state is updated by the node thread
    while(StateUpdated == false)
        StateConditionVariable.wait(UniqueLock);

    // Reset the StateUpdated flag
    StateUpdated = false;

    // State save
    ReadState = State;

    // Releasing the node thread;
    StateConditionVariable.notify_all();

    // Take the state and unlock the mutex
    return ReadState;
}

void TreeNode::SetNodeState(NodeState StateToBeSet)
{
    // Lock acquistion
    std::unique_lock<std::mutex> UniqueLock(StateMutex);

    // State update
    State = StateToBeSet;
    StateUpdated = true;

    // Notification and unlock of the mutex
    StateConditionVariable.notify_all();

    // Waiting for the father to read the state
    StateConditionVariable.wait(UniqueLock);
}

NodeState TreeNode::ReadState()
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    return State;
}
