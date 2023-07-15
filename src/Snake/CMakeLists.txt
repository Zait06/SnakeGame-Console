add_library(Snake STATIC Snake.h Snake.cpp)

target_include_directories(Snake PUBLIC ${CMAKE_CURRENT_LIST_DIR})
