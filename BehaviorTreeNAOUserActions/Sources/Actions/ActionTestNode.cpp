#include "ActionTestNode.h"

using namespace BT;

ActionTestNode::ActionTestNode(std::string Name) : ActionNode::ActionNode(Name)
{
    Type = Action;

    // Thread start
    Thread = new std::thread(&ActionTestNode::Exec, this);
    Thread->detach();
}

void ActionTestNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        // Running state
        SetNodeState(Running);
        std::cout << Name << " returning " << Running << "!" << std::endl;

        // Perform action...
        int i=0;
        while(ReadState() != Halted and i++<30)
        {
            std::cout << Name << " working!" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
        }

        if (i<30)
        {
            std::cout << Name << " Halted!" << std::endl;

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
                std::cout << Name << " Halted!" << std::endl;

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

bool ActionTestNode::Halt()
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
