cmake_minimum_required(VERSION 3.19)
project(Speedrun)

set(CMAKE_C_STANDARD 11)

# Main source files
set(MAIN_SOURCES 
    src/main.c)

# Util source files
set(UTIL_SOURCES 
    src/util/umath.c)

# Core source files
set(CORE_SOURCES 
    src/core/grid.c
    src/core/player.c)

find_package(raylib 3.0 QUIET)

add_executable(${PROJECT_NAME} ${MAIN_SOURCES} ${UTIL_SOURCES} ${CORE_SOURCES})

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

target_link_libraries(${PROJECT_NAME} raylib)
