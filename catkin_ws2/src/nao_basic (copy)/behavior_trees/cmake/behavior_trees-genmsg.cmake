# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "behavior_trees: 7 messages, 0 services")

set(MSG_I_FLAGS "-Ibehavior_trees:/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg;-Iactionlib_msgs:/opt/ros/hydro/share/actionlib_msgs/cmake/../msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(behavior_trees_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
)
_generate_msg_cpp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
)
_generate_msg_cpp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
)
_generate_msg_cpp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
)
_generate_msg_cpp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSAction.msg"
  "${MSG_I_FLAGS}"
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionGoal.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionResult.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
)
_generate_msg_cpp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
)
_generate_msg_cpp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
)

### Generating Services

### Generating Module File
_generate_module_cpp(behavior_trees
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(behavior_trees_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(behavior_trees_generate_messages behavior_trees_generate_messages_cpp)

# target for backward compatibility
add_custom_target(behavior_trees_gencpp)
add_dependencies(behavior_trees_gencpp behavior_trees_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS behavior_trees_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
)
_generate_msg_lisp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
)
_generate_msg_lisp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
)
_generate_msg_lisp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
)
_generate_msg_lisp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSAction.msg"
  "${MSG_I_FLAGS}"
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionGoal.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionResult.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
)
_generate_msg_lisp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
)
_generate_msg_lisp(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
)

### Generating Services

### Generating Module File
_generate_module_lisp(behavior_trees
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(behavior_trees_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(behavior_trees_generate_messages behavior_trees_generate_messages_lisp)

# target for backward compatibility
add_custom_target(behavior_trees_genlisp)
add_dependencies(behavior_trees_genlisp behavior_trees_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS behavior_trees_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
)
_generate_msg_py(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
)
_generate_msg_py(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
)
_generate_msg_py(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
)
_generate_msg_py(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSAction.msg"
  "${MSG_I_FLAGS}"
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSFeedback.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionGoal.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionResult.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
)
_generate_msg_py(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
)
_generate_msg_py(behavior_trees
  "/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/michele/catkin_ws/src/nao_basic/devel/share/behavior_trees/msg/ROSGoal.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
)

### Generating Services

### Generating Module File
_generate_module_py(behavior_trees
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(behavior_trees_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(behavior_trees_generate_messages behavior_trees_generate_messages_py)

# target for backward compatibility
add_custom_target(behavior_trees_genpy)
add_dependencies(behavior_trees_genpy behavior_trees_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS behavior_trees_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/behavior_trees
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(behavior_trees_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
add_dependencies(behavior_trees_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/behavior_trees
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(behavior_trees_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
add_dependencies(behavior_trees_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/behavior_trees
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(behavior_trees_generate_messages_py actionlib_msgs_generate_messages_py)
add_dependencies(behavior_trees_generate_messages_py std_msgs_generate_messages_py)
