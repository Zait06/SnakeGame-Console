add_library(system_actions STATIC system_actions.h system_actions.cpp)

target_include_directories(system_actions PUBLIC ${CMAKE_CURRENT_LIST_DIR})