# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ltl3: 4 messages, 0 services")

set(MSG_I_FLAGS "-Iltl3:/home/reconfig2/catkin_ws/src/ltl3/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ltl3_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/knowledge.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ltl3
)
_generate_msg_cpp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/confirmation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ltl3
)
_generate_msg_cpp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ltl3
)
_generate_msg_cpp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/activity.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ltl3
)

### Generating Services

### Generating Module File
_generate_module_cpp(ltl3
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ltl3
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ltl3_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ltl3_generate_messages ltl3_generate_messages_cpp)

# target for backward compatibility
add_custom_target(ltl3_gencpp)
add_dependencies(ltl3_gencpp ltl3_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ltl3_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/knowledge.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ltl3
)
_generate_msg_lisp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/confirmation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ltl3
)
_generate_msg_lisp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ltl3
)
_generate_msg_lisp(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/activity.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ltl3
)

### Generating Services

### Generating Module File
_generate_module_lisp(ltl3
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ltl3
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ltl3_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ltl3_generate_messages ltl3_generate_messages_lisp)

# target for backward compatibility
add_custom_target(ltl3_genlisp)
add_dependencies(ltl3_genlisp ltl3_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ltl3_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/knowledge.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3
)
_generate_msg_py(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/confirmation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3
)
_generate_msg_py(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3
)
_generate_msg_py(ltl3
  "/home/reconfig2/catkin_ws/src/ltl3/msg/activity.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3
)

### Generating Services

### Generating Module File
_generate_module_py(ltl3
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ltl3_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ltl3_generate_messages ltl3_generate_messages_py)

# target for backward compatibility
add_custom_target(ltl3_genpy)
add_dependencies(ltl3_genpy ltl3_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ltl3_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ltl3)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ltl3
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(ltl3_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ltl3)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ltl3
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(ltl3_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ltl3
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(ltl3_generate_messages_py std_msgs_generate_messages_py)
