# Declare the version of the CMake API for forward-compatibility

cmake_minimum_required(VERSION 2.8)
# Declare the name of the CMake Project

project(Game_project)

# Add the directory to search for header files

include_directories(include)

add_compile_options("-Wall" "-Wpedantic" "-Wextra" "-fexceptions" "-O0" "-g3" "-ggdb")

# Define an executable target
set(CMAKE_BUILD_TYPE Debug)
add_executable(init_robots src/robot.cpp src/init.cpp)
add_executable(init_robots_with_grid src/init_robots_with_grid.cpp src/robot.cpp)
add_executable(game_static_robots src/game_static_robots.cpp src/robot.cpp)
add_executable(game src/game.cpp src/robot.cpp src/robotai.cpp)