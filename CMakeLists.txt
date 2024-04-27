cmake_minimum_required(VERSION 3.2)

project(SnakeGameConsole)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

add_executable(
    SnakeGame 
    src/main.cpp
    src/system_actions/system_actions.h
    src/system_actions/system_actions.cpp
    src/utils/screen.h
    src/utils/screen.cpp
    src/utils/keyboard.h
    src/utils/keyboard.cpp
    src/Food/Food.h
    src/Food/Food.cpp
    src/Snake/Snake.h
    src/Snake/Snake.cpp
    src/Game/Game.h
    src/Game/Game.cpp
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sounds DESTINATION ${CMAKE_CURRENT_BINARY_DIR})