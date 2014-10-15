cmake_minimum_required(VERSION 2.8.3)
project(nao_basic)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  message_generation
  roscpp
  roslib
  rospy
  std_msgs
  behavior_trees
)

# System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system thread program_options)

# NAO
find_package(ALCOMMON  REQUIRED)
find_package(ALPROXIES REQUIRED)
find_package(ALVISION  REQUIRED)
find_package(ALVALUE   REQUIRED)

find_package(OpenCV    REQUIRED)

# Settings
add_definitions(-Wall -g -O0 -Wno-deprecated -static -Bstatic -std=gnu++0x)

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

# Generate messages in the 'msg' folder
add_message_files(
  FILES
  activity.msg
  confirmation.msg
)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

# Generate added messages and services with any dependencies listed here
generate_messages(
#   DEPENDENCIES
#   actionlib_msgs#   std_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES nao_basic
#  CATKIN_DEPENDS actionlib actionlib_msgs roscpp roslib rospy std_msgs
  DEPENDS bt_server
  DEPENDS Boost
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${ALCOMMON_INCLUDE_DIRS}
)

## Declare a cpp library
# add_library(nao_basic
#   src/${PROJECT_NAME}/nao_basic.cpp
# )

## Declare a cpp executable
# add_executable(nao_basic_node src/nao_basic_node.cpp)

file(GLOB_RECURSE COMMON_SRC ${PROJECT_SOURCE_DIR}/src/common/*.cpp)
set(COMMON_LIB ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${ALPROXIES_LIBRARIES} ${ALCOMMON_LIBRARIES} ${ALVISION_LIBRARIES} ${ALVALUE_LIBRARIES} ${OpenCV_LIBS})

add_executable(BallTrackerBT src/bt/ball_tracker_bt.cpp ${COMMON_SRC})
target_link_libraries(BallTrackerBT ${COMMON_LIB})

add_executable(BallGrasperBT src/bt/ball_grasper_bt.cpp ${COMMON_SRC})
target_link_libraries(BallGrasperBT ${COMMON_LIB})

add_executable(BallThrowerBT src/bt/ball_thrower_bt.cpp ${COMMON_SRC})
target_link_libraries(BallThrowerBT ${COMMON_LIB})

add_executable(WalkerBT src/bt/walker_bt.cpp ${COMMON_SRC})
target_link_libraries(WalkerBT ${COMMON_LIB})

add_executable(HandMoverBT src/bt/hand_mover_bt.cpp ${COMMON_SRC})
target_link_libraries(HandMoverBT ${COMMON_LIB})

add_executable(MoveForwardBT src/bt/move_forward_bt.cpp ${COMMON_SRC})
target_link_libraries(MoveForwardBT ${COMMON_LIB})

add_executable(BatteryLevelBT src/journal/cond_battery_level_bt.cpp ${COMMON_SRC})
target_link_libraries(BatteryLevelBT ${COMMON_LIB})

add_executable(BumpersBT src/journal/cond_bumpers_bt.cpp ${COMMON_SRC})
target_link_libraries(BumpersBT ${COMMON_LIB})

add_executable(TemperatureLevelBT src/journal/cond_temperature_level_bt.cpp ${COMMON_SRC})
target_link_libraries(TemperatureLevelBT ${COMMON_LIB})

add_executable(SayRechargeMeBT src/journal/say_recharge_bt.cpp ${COMMON_SRC})
target_link_libraries(SayRechargeMeBT ${COMMON_LIB})

add_executable(SayWhatYouWantBT src/journal/say_what_you_want_bt.cpp ${COMMON_SRC})
target_link_libraries(SayWhatYouWantBT ${COMMON_LIB})

add_executable(SayHotBT src/journal/say_hot_bt.cpp ${COMMON_SRC})
target_link_libraries(SayHotBT ${COMMON_LIB})

add_executable(SayFootBT src/journal/say_foot_bt.cpp ${COMMON_SRC})
target_link_libraries(SayFootBT ${COMMON_LIB})

add_executable(SetActivityBT src/journal/set_activity_bt.cpp ${COMMON_SRC})
target_link_libraries(SetActivityBT ${COMMON_LIB})

add_executable(KnowsActivityBT src/journal/cond_knows_activity_bt.cpp ${COMMON_SRC})
target_link_libraries(KnowsActivityBT ${COMMON_LIB})

add_executable(IsActivitySitBT src/journal/cond_is_activity_sit_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivitySitBT ${COMMON_LIB})

add_executable(IsActivityGoodbyeBT src/journal/cond_is_activity_goodbye_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivityGoodbyeBT ${COMMON_LIB})

add_executable(SayGoodbyeBT src/journal/say_goodbye_bt.cpp ${COMMON_SRC})
target_link_libraries(SayGoodbyeBT ${COMMON_LIB})

add_executable(IsActivityStandBT src/journal/cond_is_activity_stand_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivityStandBT ${COMMON_LIB})

add_executable(SitDownBT src/journal/sit_down_bt.cpp ${COMMON_SRC})
target_link_libraries(SitDownBT ${COMMON_LIB})

add_executable(IsActivityPictureBT src/journal/cond_is_activity_picture_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivityPictureBT  ${COMMON_LIB})

add_executable(RunPictureGameBT src/journal/run_picture_game_bt.cpp ${COMMON_SRC})
target_link_libraries(RunPictureGameBT ${COMMON_LIB})

add_executable(IsActivitySoundBT src/journal/cond_is_activity_sound_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivitySoundBT  ${COMMON_LIB})

add_executable(RunSoundTrackerBT src/journal/run_sound_tracker_bt.cpp ${COMMON_SRC})
target_link_libraries(RunSoundTrackerBT ${COMMON_LIB})

add_executable(IsActivityEyesBT src/journal/cond_is_activity_eyes_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivityEyesBT  ${COMMON_LIB})

add_executable(RunMovTrackerBT src/journal/run_mov_tracker_bt.cpp ${COMMON_SRC})
target_link_libraries(RunMovTrackerBT ${COMMON_LIB})

add_executable(IsActivityDanceBT src/journal/cond_is_activity_dance_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivityDanceBT  ${COMMON_LIB})

add_executable(RunDanceBT src/journal/run_dance_bt.cpp ${COMMON_SRC})
target_link_libraries(RunDanceBT ${COMMON_LIB})


add_executable(IsActivitySleepBT src/journal/cond_is_activity_sleep_bt.cpp ${COMMON_SRC})
target_link_libraries(IsActivitySleepBT  ${COMMON_LIB})

add_executable(RunSleepBT src/journal/run_sleep_bt.cpp ${COMMON_SRC})
target_link_libraries(RunSleepBT ${COMMON_LIB})


add_executable(StandUpBT src/journal/stand_up_bt.cpp ${COMMON_SRC})
target_link_libraries(StandUpBT ${COMMON_LIB})

add_executable(ResetActivityBT src/journal/reset_activity_bt.cpp ${COMMON_SRC})
target_link_libraries(ResetActivityBT ${COMMON_LIB})

add_executable(BackUpBT src/journal/back_up_bt.cpp ${COMMON_SRC})
target_link_libraries(BackUpBT ${COMMON_LIB})

add_executable(BallDetectorTest src/test/ball_detector.cpp)
target_link_libraries(BallDetectorTest ${COMMON_LIB})

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(nao_basic_node nao_basic_generate_messages_cpp)

## Specify libraries to link a library or executable target against
# target_link_libraries(nao_basic_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS nao_basic nao_basic_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_nao_basic.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
