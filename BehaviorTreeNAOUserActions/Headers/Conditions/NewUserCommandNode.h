#ifndef NEWUSERCOMMANDNODE_H
#define NEWUSERCOMMANDNODE_H

#include "ConditionNode.h"

namespace BT
{
    class NewUserCommandNode : public ConditionNode
    {
        using ConditionNode::ConditionNode;
    private:
        // Sync for input thread
        NodeSemaphore *InputSempaohore;

        // Variables for inputs
        bool ChoiceUpdated;
        std::mutex ChoiceMutex;
    public:
        // Constructor
        NewUserCommandNode(std::string Name);

        // The method that is going to be executed by the thread
        void Exec();

        // The method that is going to be executed by the input thread
        void ReadInput();
    };
}

#endif
