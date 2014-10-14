# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "nao_basic: 2 messages, 0 services")

set(MSG_I_FLAGS "-Inao_basic:/home/michele/catkin_ws/src/nao_basic/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(nao_basic_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(nao_basic
  "/home/michele/catkin_ws/src/nao_basic/msg/confirmation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/nao_basic
)
_generate_msg_cpp(nao_basic
  "/home/michele/catkin_ws/src/nao_basic/msg/activity.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/nao_basic
)

### Generating Services

### Generating Module File
_generate_module_cpp(nao_basic
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/nao_basic
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(nao_basic_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(nao_basic_generate_messages nao_basic_generate_messages_cpp)

# target for backward compatibility
add_custom_target(nao_basic_gencpp)
add_dependencies(nao_basic_gencpp nao_basic_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS nao_basic_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(nao_basic
  "/home/michele/catkin_ws/src/nao_basic/msg/confirmation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/nao_basic
)
_generate_msg_lisp(nao_basic
  "/home/michele/catkin_ws/src/nao_basic/msg/activity.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/nao_basic
)

### Generating Services

### Generating Module File
_generate_module_lisp(nao_basic
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/nao_basic
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(nao_basic_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(nao_basic_generate_messages nao_basic_generate_messages_lisp)

# target for backward compatibility
add_custom_target(nao_basic_genlisp)
add_dependencies(nao_basic_genlisp nao_basic_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS nao_basic_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(nao_basic
  "/home/michele/catkin_ws/src/nao_basic/msg/confirmation.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/nao_basic
)
_generate_msg_py(nao_basic
  "/home/michele/catkin_ws/src/nao_basic/msg/activity.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/nao_basic
)

### Generating Services

### Generating Module File
_generate_module_py(nao_basic
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/nao_basic
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(nao_basic_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(nao_basic_generate_messages nao_basic_generate_messages_py)

# target for backward compatibility
add_custom_target(nao_basic_genpy)
add_dependencies(nao_basic_genpy nao_basic_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS nao_basic_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/nao_basic)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/nao_basic
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/nao_basic)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/nao_basic
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/nao_basic)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/nao_basic\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/nao_basic
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
