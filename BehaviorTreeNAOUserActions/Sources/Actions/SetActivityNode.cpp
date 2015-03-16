#include "SetActivityNode.h"

using namespace BT;

SetActivityNode::SetActivityNode(std::string Name) : ActionNode::ActionNode(Name)
{
    Type = Action;

    // Thread start
    Thread = new std::thread(&SetActivityNode::Exec, this);
    Thread->detach();
}

void SetActivityNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        // Running state
        SetNodeState(Running);
        std::cout << Name << " returning " << Running << "!" << std::endl;

        // Perform action...
        DesiredActionMutex.lock();
        switch (Choice)
        {
        case 1:
            DesiredAction = NAO::Sit;
            break;
        case 2:
            DesiredAction = NAO::Stand;
            break;
        case 3:
            DesiredAction = NAO::Walk;
            break;
        default:
            break;
        }
        DesiredActionMutex.unlock();

        if (ReadState() == Halted)
        {
            // std::cout << Name << " Halted!" << std::endl;

            // Resetting the state
            WriteState(Idle);

            // Next loop
            continue;
        }
        else
        {
            // trying to set the outcome state:
            if (WriteState(Success) != true)
            {
                // meanwhile, my father halted me!
                // std::cout << Name << " Halted!" << std::endl;

                // Resetting the state
                WriteState(Idle);

                // Next loop
                continue;
            }

            std::cout << Name << " returning " << Success << "!" << std::endl;
        }

        // Synchronization
        // (my father is telling me that it has read my new state)
        Semaphore.Wait();

        // Resetting the state
        WriteState(Idle);
    }
}

bool SetActivityNode::Halt()
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    // Checking for "Running" correctness
    if (State != Running)
    {
        return false;
    }

    State = Halted;
    return true;
}
