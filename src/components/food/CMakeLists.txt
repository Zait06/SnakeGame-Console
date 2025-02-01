add_library(food STATIC food.h food.cpp)
target_link_libraries(food utils)
target_include_directories(food PUBLIC ${CMAKE_CURRENT_LIST_DIR})