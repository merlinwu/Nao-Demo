#include "ToeBumperPressedNode.h"

using namespace BT;

ToeBumperPressedNode::ToeBumperPressedNode(std::string Name) : ConditionNode::ConditionNode(Name)
{
    Type = Condition;

    // Thread start
    Thread = new std::thread(&ToeBumperPressedNode::Exec, this);
    Thread->detach();
}

void ToeBumperPressedNode::Exec()
{
    while(true)
    {
        // Waiting for a tick to come
        Semaphore.Wait();

        if ((float)MemoryProxy->getData("RightBumperPressed") > 0.5 ||
                (float)MemoryProxy->getData("LeftBumperPressed") > 0.5)
        {
            SetNodeState(Success);
        }
        else
        {
            SetNodeState(Failure);
        }

        // SetNodeState(Failure);

        // Resetting the state
        WriteState(Idle);
    }
}
