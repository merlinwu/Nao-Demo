#include "IsMoveNode.h"

using namespace BT;

IsMoveNode::IsMoveNode(std::string Name) : ConditionNode::ConditionNode(Name)
{
    Type = Condition;

    // Thread start
    Thread = new std::thread(&IsMoveNode::Exec, this);
    Thread->detach();
}

void IsMoveNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        DesiredActionMutex.lock();

        if (DesiredAction == NAO::Walk)
        {
            SetNodeState(Success);
        }
        else
        {
            SetNodeState(Failure);
        }

        DesiredActionMutex.unlock();

        // Resetting the state
        WriteState(Idle);
    }
}
