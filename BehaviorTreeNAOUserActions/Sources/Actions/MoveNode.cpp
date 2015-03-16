#include "MoveNode.h"

using namespace BT;

MoveNode::MoveNode(std::string Name) : ActionNode::ActionNode(Name)
{
    Type = Action;

    // Thread start
    Thread = new std::thread(&MoveNode::Exec, this);
    Thread->detach();
}

void MoveNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        // Running state
        SetNodeState(Running);
        std::cout << Name << " returning " << Running << "!" << std::endl;

        // Perform action...
        MotionProxy->moveInit();
        MotionProxy->move(0.1, 0, 0);
        while (ReadState() != Halted)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        // int i = 0;
        // while (i++ < 500 && ReadState() != Halted) std::this_thread::sleep_for(std::chrono::milliseconds(10));

        DesiredActionMutex.lock();
        if (DesiredAction == NAO::Walk)
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

bool MoveNode::Halt()
{
    // Lock acquistion
    std::lock_guard<std::mutex> LockGuard(StateMutex);

    // Checking for "Running" correctness
    if (State != Running)
    {
        return false;
    }

    if (BackOffFlag == false)
    {
        MotionProxy->stopMove();
    }

    State = Halted;
    return true;
}
