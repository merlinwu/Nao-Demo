#include "LeafNode.h"

using namespace BT;

LeafNode::LeafNode(std::string Name) : TreeNode::TreeNode(Name)
{
    MemoryProxy = new AL::ALMemoryProxy(RobotAddress, RobotPort);
    BehaviorProxy = new AL::ALBehaviorManagerProxy(RobotAddress, RobotPort);
    SpeachProxy = new AL::ALTextToSpeechProxy(RobotAddress, RobotPort);
    MotionProxy = new AL::ALMotionProxy(RobotAddress, RobotPort);
}
