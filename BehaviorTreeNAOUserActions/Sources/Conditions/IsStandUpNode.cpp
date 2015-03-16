#include "IsStandUpNode.h"

using namespace BT;

IsStandUpNode::IsStandUpNode(std::string Name) : ConditionNode::ConditionNode(Name)
{
    Type = Condition;

    // Thread start
    Thread = new std::thread(&IsStandUpNode::Exec, this);
    Thread->detach();
}

void IsStandUpNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        DesiredActionMutex.lock();

        if (DesiredAction == NAO::Stand)
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
