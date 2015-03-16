#ifndef LEAFNODE_H
#define LEAFNODE_H

#include "TreeNode.h"

// Global robot variable
extern NAO::RobotAction DesiredAction;
extern std::mutex DesiredActionMutex;
extern bool BackOffFlag;

namespace BT
{
    class LeafNode : public TreeNode
    {
        using TreeNode::TreeNode;
    protected:
        // Used to access memory or registers
        AL::ALMemoryProxy* MemoryProxy;

        // Used to control the behavior of the robot
        AL::ALBehaviorManagerProxy* BehaviorProxy;

        // Used to make the robot speach
        AL::ALTextToSpeechProxy* SpeachProxy;

        // Used to make the robot move
        AL::ALMotionProxy* MotionProxy;
    public:
        // Constructor
        LeafNode(std::string Name);
    };
}

#endif
