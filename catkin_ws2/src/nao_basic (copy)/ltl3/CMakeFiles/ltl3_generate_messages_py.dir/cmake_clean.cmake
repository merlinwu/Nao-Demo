FILE(REMOVE_RECURSE
  "CMakeFiles/ltl3_generate_messages_py"
  "../devel/lib/python2.7/dist-packages/ltl3/msg/_knowledge.py"
  "../devel/lib/python2.7/dist-packages/ltl3/msg/_confirmation.py"
  "../devel/lib/python2.7/dist-packages/ltl3/msg/_pose.py"
  "../devel/lib/python2.7/dist-packages/ltl3/msg/_activity.py"
  "../devel/lib/python2.7/dist-packages/ltl3/msg/__init__.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ltl3_generate_messages_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
