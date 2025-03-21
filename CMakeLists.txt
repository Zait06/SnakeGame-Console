cmake_minimum_required(VERSION 3.20)

project(SnakeGameConsole VERSION 1.0.2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

add_subdirectory(src)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})



# # Install the executable
# install(TARGETS SnakeGame DESTINATION bin)

# # Include system libraries (necessary for Windows)
# include(InstallRequiredSystemLibraries)

# # Configure CPack
# set(CPACK_PACKAGE_NAME ${SnakeGameConsole})
# set(CPACK_PACKAGE_VERSION "1.0.0")
# set(CPACK_PACKAGE_VENDOR "Tenoch")
# include(CPack)