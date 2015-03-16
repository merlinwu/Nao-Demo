#include <iostream>
#include <chrono>
#include <functional>
#include <mutex>

#include "BehaviorTree.h"

using namespace BT;

// Global robot variable
NAO::RobotAction DesiredAction = NAO::None;
std::mutex DesiredActionMutex;

int main()
{
    try
    {
        BehaviorTree    Tree("Tree");
        BehaviorTree&   SubTree = Tree.CreateNewSubTree("SubTree");

        Tree.CreateNewControlNode("SelectorNode1", Selector);
        Tree.CreateNewControlNode("SequenceNode1", Sequence);
        Tree.CreateNewControlNode("ParallelNode1", Parallel);
        Tree.CreateNewControlNode("ParallelNode2", Parallel);
        Tree.CreateNewControlNode("SequenceNode2", Sequence);
        Tree.CreateNewControlNode("SequenceNode3", Sequence);

        Tree.SetRootNode("SelectorNode1");

        Tree.CreateNewConditionNode("ToeBumberPressed", ToeBumperPressed);
        Tree.CreateNewActionNode("Speak", Speak);
        Tree.CreateNewActionNode("BackOff", BackOff);
        Tree.CreateNewConditionNode("KnowWhatToDo", KnowWhatToDo);
        Tree.CreateNewConditionNode("NewUserCommand", NewUserCommand);
        Tree.CreateNewActionNode("SetActivity", SetActivity);

        Tree.SetFatherChildRelationship("SelectorNode1", "SequenceNode1");
        Tree.SetFatherChildRelationship("SelectorNode1", "ParallelNode1");
        Tree.SetFatherChildRelationship("SequenceNode1", "ToeBumberPressed");
        Tree.SetFatherChildRelationship("SequenceNode1", "ParallelNode2");
        Tree.SetFatherChildRelationship("ParallelNode2", "Speak");
        Tree.SetFatherChildRelationship("ParallelNode2", "BackOff");
        Tree.SetFatherChildRelationship("ParallelNode1", "SequenceNode2");
        Tree.SetFatherChildRelationship("ParallelNode1", "SequenceNode3");
        Tree.SetFatherChildRelationship("SequenceNode3", "NewUserCommand");
        Tree.SetFatherChildRelationship("SequenceNode3", "SetActivity");
        Tree.SetFatherChildRelationship("SequenceNode2", "KnowWhatToDo");

        Tree.SetParallelNodeThreshold("ParallelNode1", 1);
        Tree.SetParallelNodeThreshold("ParallelNode2", 2);

        SubTree.CreateNewControlNode("ParallelNode1", Parallel);
        SubTree.CreateNewControlNode("SequenceNode1", Sequence);
        SubTree.CreateNewControlNode("SequenceNode2", Sequence);
        SubTree.CreateNewControlNode("SequenceNode3", Sequence);
        SubTree.CreateNewConditionNode("IsCrouch", IsCrouch);
        SubTree.CreateNewConditionNode("IsStandUp", IsStandUp);
        SubTree.CreateNewConditionNode("IsMove", IsMove);
        SubTree.CreateNewActionNode("Crouch", Crouch);
        SubTree.CreateNewActionNode("StandUp", StandUp);
        SubTree.CreateNewActionNode("Move", Move);

        SubTree.SetRootNode("ParallelNode1");

        SubTree.SetFatherChildRelationship("ParallelNode1", "SequenceNode1");
        SubTree.SetFatherChildRelationship("ParallelNode1", "SequenceNode2");
        SubTree.SetFatherChildRelationship("ParallelNode1", "SequenceNode3");
        SubTree.SetFatherChildRelationship("SequenceNode1", "IsCrouch");
        SubTree.SetFatherChildRelationship("SequenceNode1", "Crouch");
        SubTree.SetFatherChildRelationship("SequenceNode2", "IsStandUp");
        SubTree.SetFatherChildRelationship("SequenceNode2", "StandUp");
        SubTree.SetFatherChildRelationship("SequenceNode3", "IsMove");
        SubTree.SetFatherChildRelationship("SequenceNode3", "Move");

        SubTree.SetParallelNodeThreshold("ParallelNode1", 1);

        Tree.SetFatherChildRelationship("SequenceNode2", "SubTree");

        /*
        Tree.CreateNewControlNode("SequenceNode1", Sequence, 0);
        Tree.SetRootNode("SequenceNode1");

        Tree.CreateNewControlNode("SelectorNode1", Selector, 0);
        Tree.CreateNewConditionNode("ConditionNode1", ConditionTest);
        Tree.CreateNewActionNode("ActionNode1", ActionTest);

        Tree.SetFatherChildRelationship("SequenceNode1", "SelectorNode1");
        Tree.SetFatherChildRelationship("SelectorNode1", "ConditionNode1");
        Tree.SetFatherChildRelationship("SelectorNode1", "ActionNode1");

        SubTree.CreateNewControlNode("SelectorNode2", Selector, 0);
        SubTree.SetRootNode("SelectorNode2");

        SubTree.CreateNewConditionNode("ConditionNode2", ConditionTest);
        SubTree.CreateNewControlNode("SequenceNode2", Sequence, 0);
        SubTree.CreateNewConditionNode("ConditionNode3", ConditionTest);
        SubTree.CreateNewActionNode("ActionNode2", ActionTest);

        SubTree.SetFatherChildRelationship("SelectorNode2", "ConditionNode2");
        SubTree.SetFatherChildRelationship("SelectorNode2", "SequenceNode2");
        SubTree.SetFatherChildRelationship("SequenceNode2", "ConditionNode3");
        SubTree.SetFatherChildRelationship("SequenceNode2", "ActionNode2");
        */

        /*
        Tree.CreateNewControlNode("SequenceNode1", Sequence);

        Tree.CreateNewConditionNode("ConditionNode1", ConditionTest);
        Tree.SetFatherChildRelationship("SequenceNode1", "ConditionNode1");
        Tree.SetRootNode("SequenceNode1");

        SubTree.CreateNewControlNode("ParallelNode1", Parallel);
        SubTree.CreateNewConditionNode("ConditionNode2", ConditionTest);
        SubTree.CreateNewActionNode("ActionNode1", ActionTest);
        SubTree.CreateNewActionNode("ActionNode2", ActionTest);

        SubTree.SetFatherChildRelationship("ParallelNode1", "ActionNode1");
        SubTree.SetFatherChildRelationship("ParallelNode1", "ActionNode2");
        SubTree.SetFatherChildRelationship("ParallelNode1", "ConditionNode2");
        SubTree.SetParallelNodeThreshold("ParallelNode1", 1);
        SubTree.SetRootNode("ParallelNode1");

        Tree.SetFatherChildRelationship("SequenceNode1", "SubTree");
        */

        for(int i=0; i>-1; i++)
        {
            // Ticking the root node
            Tree.Tick();

            // Printing its state
            Tree.GetTreeState();
            // std::cout << Tree.Name << " returned " << Tree.GetTreeState() << "!" << std::endl << std::endl;

            // Simulating the tick period
            std::this_thread::sleep_for(std::chrono::milliseconds(Tree.TickPeriod));
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
    catch (std::exception& Exception)
    {
        std::cout << Exception.what() << std::endl;
    }

    return 0;
}

