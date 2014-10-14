# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ar_tracker: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iar_tracker:/home/michele/catkin_ws/src/ar_tracker/msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ar_tracker_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ar_tracker
  "/home/michele/catkin_ws/src/ar_tracker/msg/ARMarker.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ar_tracker
)

### Generating Services

### Generating Module File
_generate_module_cpp(ar_tracker
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ar_tracker
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ar_tracker_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ar_tracker_generate_messages ar_tracker_generate_messages_cpp)

# target for backward compatibility
add_custom_target(ar_tracker_gencpp)
add_dependencies(ar_tracker_gencpp ar_tracker_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ar_tracker_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(ar_tracker
  "/home/michele/catkin_ws/src/ar_tracker/msg/ARMarker.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ar_tracker
)

### Generating Services

### Generating Module File
_generate_module_lisp(ar_tracker
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ar_tracker
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(ar_tracker_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(ar_tracker_generate_messages ar_tracker_generate_messages_lisp)

# target for backward compatibility
add_custom_target(ar_tracker_genlisp)
add_dependencies(ar_tracker_genlisp ar_tracker_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ar_tracker_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ar_tracker
  "/home/michele/catkin_ws/src/ar_tracker/msg/ARMarker.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ar_tracker
)

### Generating Services

### Generating Module File
_generate_module_py(ar_tracker
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ar_tracker
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ar_tracker_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ar_tracker_generate_messages ar_tracker_generate_messages_py)

# target for backward compatibility
add_custom_target(ar_tracker_genpy)
add_dependencies(ar_tracker_genpy ar_tracker_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ar_tracker_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ar_tracker)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ar_tracker
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(ar_tracker_generate_messages_cpp geometry_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ar_tracker)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/ar_tracker
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(ar_tracker_generate_messages_lisp geometry_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ar_tracker)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ar_tracker\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ar_tracker
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(ar_tracker_generate_messages_py geometry_msgs_generate_messages_py)
