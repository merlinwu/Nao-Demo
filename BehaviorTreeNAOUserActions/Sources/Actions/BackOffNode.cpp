#include "BackOffNode.h"

using namespace BT;

bool BackOffFlag = false;

BackOffNode::BackOffNode(std::string Name) : ActionNode::ActionNode(Name)
{
    Type = Action;

    // Thread start
    Thread = new std::thread(&BackOffNode::Exec, this);
    Thread->detach();
}

void BackOffNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        // Running state
        SetNodeState(Running);
        std::cout << Name << " returning " << Running << "!" << std::endl;

        // Perform action...
        if (MotionProxy->moveIsActive())
        {
            MotionProxy->stopMove();
        }
        BackOffFlag = true;
        BehaviorProxy->runBehavior("back_off");
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));

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

        BackOffFlag = false;

        // Synchronization
        // (my father is telling me that it has read my new state)
        Semaphore.Wait();

        // Resetting the state
        WriteState(Idle);
    }
}

bool BackOffNode::Halt()
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    // Checking for "Running" correctness
    if (State != Running)
    {
        return false;
    }

    BehaviorProxy->stopBehavior("back_off");

    State = Halted;
    return true;
}
