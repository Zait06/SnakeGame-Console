add_library(Comida STATIC Comida.h Comida.cpp)

target_include_directories(Comida PUBLIC ${CMAKE_CURRENT_LIST_DIR})
