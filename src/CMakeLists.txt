add_subdirectory(utils)
add_subdirectory(system_actions)
add_subdirectory(components)
add_subdirectory(game)

add_executable(SnakeGame main.cpp)
target_link_libraries(SnakeGame utils game)