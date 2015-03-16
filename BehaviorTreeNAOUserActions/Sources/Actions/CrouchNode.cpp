#include "CrouchNode.h"

using namespace BT;

CrouchNode::CrouchNode(std::string Name) : ActionNode::ActionNode(Name)
{
    Type = Action;

    // Thread start
    Thread = new std::thread(&CrouchNode::Exec, this);
    Thread->detach();
}

void CrouchNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        // Running state
        SetNodeState(Running);
        std::cout << Name << " returning " << Running << "!" << std::endl;

        // Perform action...
        BehaviorProxy->runBehavior("crouch");
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        DesiredActionMutex.lock();
        if (DesiredAction == NAO::Sit)
        {
            DesiredAction = NAO::None;
        }
        DesiredActionMutex.unlock();

        if (ReadState() == Halted)
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

bool CrouchNode::Halt()
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    // Checking for "Running" correctness
    if (State != Running)
    {
        return false;
    }

    BehaviorProxy->stopBehavior("crouch");

    State = Halted;
    return true;
}
