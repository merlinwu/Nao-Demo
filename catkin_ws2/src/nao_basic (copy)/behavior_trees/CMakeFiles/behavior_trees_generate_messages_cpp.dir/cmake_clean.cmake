FILE(REMOVE_RECURSE
  "CMakeFiles/behavior_trees_generate_messages_cpp"
  "../devel/include/behavior_trees/ROSFeedback.h"
  "../devel/include/behavior_trees/ROSResult.h"
  "../devel/include/behavior_trees/ROSGoal.h"
  "../devel/include/behavior_trees/ROSActionFeedback.h"
  "../devel/include/behavior_trees/ROSAction.h"
  "../devel/include/behavior_trees/ROSActionResult.h"
  "../devel/include/behavior_trees/ROSActionGoal.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/behavior_trees_generate_messages_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
