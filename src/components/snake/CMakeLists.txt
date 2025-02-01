add_library(snake STATIC snake.h snake.cpp)
target_link_libraries(snake utils)
target_include_directories(snake PUBLIC ${CMAKE_CURRENT_LIST_DIR})