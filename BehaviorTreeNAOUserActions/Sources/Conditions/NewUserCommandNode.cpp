#include "NewUserCommandNode.h"

using namespace BT;

// Global input variable
unsigned int Choice = 0;

NewUserCommandNode::NewUserCommandNode(std::string Name) : ConditionNode::ConditionNode(Name)
{
    Type = Condition;

    // Thread start
    Thread = new std::thread(&NewUserCommandNode::Exec, this);
    Thread->detach();

    InputSempaohore = new NodeSemaphore(0);
}

void NewUserCommandNode::Exec()
{
    std::thread InputThread(&NewUserCommandNode::ReadInput, this);
    InputThread.detach();

    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        ChoiceMutex.lock();
        if (ChoiceUpdated == false)
        {
            SetNodeState(Failure);
            // std::cout << Name << " returning Failure" << "!" << std::endl;
        }
        else
        {
            SetNodeState(Success);
            // std::cout << Name << " returning Success" << "!" << std::endl;
            ChoiceUpdated = false;
        }
        ChoiceMutex.unlock();

        // Resetting the state
        WriteState(Idle);
    }
}

void NewUserCommandNode::ReadInput()
{
    int n;
    while (true)
    {
        std::cout << "What do you want me to do?" << std::endl;
        std::cout << "1) Crouch;" << std::endl;
        std::cout << "2) Stand Up;" << std::endl;
        std::cout << "3) Walk for 1 mt." << std::endl;
        std::cout << "Choose between (1, 2 or 3): " << std::endl;

        std::cin >> n;

        ChoiceMutex.lock();
        Choice = n;
        ChoiceUpdated = true;
        ChoiceMutex.unlock();
    }
}
