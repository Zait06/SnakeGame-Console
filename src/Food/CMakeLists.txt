add_library(Food STATIC Food.h Food.cpp)

target_include_directories(Food PUBLIC ${CMAKE_CURRENT_LIST_DIR})
