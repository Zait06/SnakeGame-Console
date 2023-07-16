cmake_minimum_required(VERSION 3.2)

project(SnakeGameConsole)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

add_subdirectory(src/utils)
# add_subdirectory(src/Food)
# add_subdirectory(src/Snake)
# add_subdirectory(src/Game)

add_executable(SnakeGame src/main.cpp)

target_link_libraries(SnakeGame utils) # Food Snake Game)
