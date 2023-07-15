add_library(utils STATIC keyboard.h keyboard.cpp screen.h screen.cpp)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_LIST_DIR})
