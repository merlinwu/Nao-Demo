FILE(REMOVE_RECURSE
  "CMakeFiles/artoolkit"
  "CMakeFiles/artoolkit-complete"
  "artoolkit/src/artoolkit-stamp/artoolkit-install"
  "artoolkit/src/artoolkit-stamp/artoolkit-mkdir"
  "artoolkit/src/artoolkit-stamp/artoolkit-download"
  "artoolkit/src/artoolkit-stamp/artoolkit-update"
  "artoolkit/src/artoolkit-stamp/artoolkit-patch"
  "artoolkit/src/artoolkit-stamp/artoolkit-configure"
  "artoolkit/src/artoolkit-stamp/artoolkit-build"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/artoolkit.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
