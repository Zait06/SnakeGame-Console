add_library(game STATIC game.h game.cpp)
target_link_libraries(game utils system_actions food snake)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_LIST_DIR})