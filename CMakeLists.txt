cmake_minimum_required(VERSION 3.17)
project(qt_minimal CXX)
set(TARGET qt_minimal)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(qt_minimal main.cpp full_screen.cpp full_screen.h)
target_link_libraries(qt_minimal Qt5::Core Qt5::Widgets)
