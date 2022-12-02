#!/bin/bash
rm -rf build-cmake
mkdir build-cmake && cd build-cmake
# /Users/atatat/Qt/6.4.1/macos
# /usr/local/Cellar/qt/6.4.0/lib/cmake
# /Users/atatat/Qt/QtDesignStudio/qt5_design_studio_reduced_version/lib/cmake/Qt5Widgets
cmake .. -DCMAKE_PREFIX_PATH="/Users/atatat/Qt/6.4.1/macos" -DQt5Widgets_DIR=/Users/atatat/Qt/QtDesignStudio/qt5_design_studio_reduced_version/lib/cmake/Qt5Widgets
