project(CPPImplementationNodesThreadsNAOUserActions)

# Needed for using threads
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

set(CMAKE_PREFIX_PATH ~/naoqi/naoqi-sdk-1.14.5-linux64)
set(LD_LIBRARY_PATH:~/naoqi/naoqi-sdk-1.14.5-linux64/lib)

cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(~/naoqi/naoqi-sdk-1.14.5-linux64/lib)

set(qibuild_DIR ~/naoqi/qibuild/build/qibuild/cmake/qibuild)
set(ALPROXIES_DIR ~/naoqi/naoqi-sdk-1.14.5-linux64/share/cmake/alproxies)
set(ALERROR_DIR ~/naoqi/naoqi-sdk-1.14.5-linux64/share/cmake/alerror)

find_package(qibuild)

# Including Headers and Sources
INCLUDE_DIRECTORIES(./Headers ./Sources)
INCLUDE_DIRECTORIES(./Headers/Actions ./Sources/Actions)
INCLUDE_DIRECTORIES(./Headers/Conditions ./Sources/Conditions)

set(HeadersList
    # General
    Headers/Include.h
    Headers/Exceptions.h
    Headers/BehaviorTree.h
    Headers/NodeSemaphore.h
    Headers/TreeNode.h
    Headers/ControlNode.h
    Headers/ParallelNode.h
    Headers/SelectorNode.h
    Headers/SequenceNode.h
    Headers/LeafNode.h
    Headers/ActionNode.h
    Headers/ConditionNode.h
    Headers/NAO.h
    # Actions
    # Headers/Actions/ActionTestNode.h
    Headers/Actions/BackOffNode.h
    Headers/Actions/CrouchNode.h
    Headers/Actions/MoveNode.h
    Headers/Actions/SetActivityNode.h
    Headers/Actions/SpeakNode.h
    Headers/Actions/StandUpNode.h
    # Conditions
    # Headers/Conditions/ConditionTestNode.h
    Headers/Conditions/IsCrouchNode.h
    Headers/Conditions/IsMoveNode.h
    Headers/Conditions/IsStandUpNode.h
    Headers/Conditions/KnowWhatToDoNode.h
    Headers/Conditions/NewUserCommandNode.h
    Headers/Conditions/ToeBumperPressedNode.h
    )
set(SourcesList
    # General
    main.cpp
    Sources/Exceptions.cpp
    Sources/BehaviorTree.cpp
    Sources/NodeSemaphore.cpp
    Sources/TreeNode.cpp
    Sources/ControlNode.cpp
    Sources/ParallelNode.cpp
    Sources/SelectorNode.cpp
    Sources/SequenceNode.cpp
    Sources/LeafNode.cpp
    Sources/ActionNode.cpp
    Sources/ConditionNode.cpp
    # Actions
    # Sources/Actions/ActionTestNode.cpp
    Sources/Actions/BackOffNode.cpp
    Sources/Actions/CrouchNode.cpp
    Sources/Actions/MoveNode.cpp
    Sources/Actions/SetActivityNode.cpp
    Sources/Actions/SpeakNode.cpp
    Sources/Actions/StandUpNode.cpp
    # Conditions
    # Sources/Conditions/ConditionTestNode.cpp
    Sources/Conditions/IsCrouchNode.cpp
    Sources/Conditions/IsMoveNode.cpp
    Sources/Conditions/IsStandUpNode.cpp
    Sources/Conditions/KnowWhatToDoNode.cpp
    Sources/Conditions/NewUserCommandNode.cpp
    Sources/Conditions/ToeBumperPressedNode.cpp
    )

qi_create_bin(${PROJECT_NAME} ${SourcesList} ${HeadersList})

qi_use_lib(${PROJECT_NAME} ALPROXIES)

