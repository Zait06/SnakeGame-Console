add_library(Game STATIC Game.h Game.cpp)

target_include_directories(Game PUBLIC ${CMAKE_CURRENT_LIST_DIR})
