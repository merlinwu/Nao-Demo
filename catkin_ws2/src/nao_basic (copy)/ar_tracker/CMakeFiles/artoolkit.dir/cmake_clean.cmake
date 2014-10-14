FILE(REMOVE_RECURSE
  "CMakeFiles/artoolkit"
  "CMakeFiles/artoolkit-complete"
  "../../ar_tracker/artoolkit/src/artoolkit-stamp/artoolkit-install"
  "../../ar_tracker/artoolkit/src/artoolkit-stamp/artoolkit-mkdir"
  "../../ar_tracker/artoolkit/src/artoolkit-stamp/artoolkit-download"
  "../../ar_tracker/artoolkit/src/artoolkit-stamp/artoolkit-update"
  "../../ar_tracker/artoolkit/src/artoolkit-stamp/artoolkit-patch"
  "../../ar_tracker/artoolkit/src/artoolkit-stamp/artoolkit-configure"
  "../../ar_tracker/artoolkit/src/artoolkit-stamp/artoolkit-build"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/artoolkit.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
