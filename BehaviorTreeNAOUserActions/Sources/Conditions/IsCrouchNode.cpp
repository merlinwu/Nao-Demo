#include "IsCrouchNode.h"

using namespace BT;

IsCrouchNode::IsCrouchNode(std::string Name) : ConditionNode::ConditionNode(Name)
{
    Type = Condition;

    // Thread start
    Thread = new std::thread(&IsCrouchNode::Exec, this);
    Thread->detach();
}

void IsCrouchNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        DesiredActionMutex.lock();

        if (DesiredAction == NAO::Sit)
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
