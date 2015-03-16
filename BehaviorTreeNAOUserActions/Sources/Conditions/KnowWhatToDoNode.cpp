#include "KnowWhatToDoNode.h"

using namespace BT;

KnowWhatToDoNode::KnowWhatToDoNode(std::string Name) : ConditionNode::ConditionNode(Name)
{
    Type = Condition;

    // Thread start
    Thread = new std::thread(&KnowWhatToDoNode::Exec, this);
    Thread->detach();
}

void KnowWhatToDoNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        DesiredActionMutex.lock();

        if (DesiredAction != NAO::None)
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
