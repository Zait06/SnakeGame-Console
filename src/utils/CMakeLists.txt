set(
    UTILS_SOURCES
    screen.h screen.cpp
    bigchars.h bigchars.cpp
    keyboard.h keyboard.cpp
)
add_library(utils STATIC ${UTILS_SOURCES})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_LIST_DIR})
