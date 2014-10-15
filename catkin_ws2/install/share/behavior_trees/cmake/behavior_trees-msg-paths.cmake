# generated from genmsg/cmake/pkg-msg-paths.cmake.em

# message include dirs in installspace
_prepend_path("${behavior_trees_DIR}/.." "msg" behavior_trees_MSG_INCLUDE_DIRS UNIQUE)
set(behavior_trees_MSG_DEPENDENCIES actionlib_msgs;std_msgs)
