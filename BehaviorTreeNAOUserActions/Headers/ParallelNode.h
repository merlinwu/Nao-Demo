#ifndef PARALLELNODE_H
#define PARALLELNODE_H

#include "ControlNode.h"

#include <limits>

namespace BT
{
    class ParallelNode : public ControlNode
    {
        using ControlNode::ControlNode;
    private:
        // N threshold
        unsigned int N;

        // Number of returned Success, Failure and Running states
        unsigned int Successes;
        unsigned int Failures;
        unsigned int Runnings;

        // Update states vector
        std::vector<bool> ChildStatesUpdated;

        // State update
        bool StateUpdate = false;
    public:
        // Constructor
        ParallelNode(std::string Name);

        // the method used to set N
        void SetThreashold(unsigned int N);

        // The method that is going to be executed by the thread
        void Exec();
    };
}

#endif
