#include "ConditionTestNode.h"

using namespace BT;

ConditionTestNode::ConditionTestNode(std::string Name) : ConditionNode::ConditionNode(Name)
{
    Type = Condition;

    // Thread start
    Thread = new std::thread(&ConditionTestNode::Exec, this);
    Thread->detach();
}

void ConditionTestNode::Exec()
{
    int i = 0;
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        // Condition checking and state update
        if ((i++/3)%2 == 0)
        {
            SetNodeState(Success);
            std::cout << Name << " returning " << Success << "!" << std::endl;
        }
        else
        {
            SetNodeState(Failure);
            std::cout << Name << " returning " << Failure << "!" << std::endl;
        }

        // Resetting the state
        WriteState(Idle);
    }
}
