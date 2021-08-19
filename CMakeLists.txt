cmake_minimum_required(VERSION 3.19)
project(Speedrun)

set(CMAKE_C_STANDARD 11)

# Main source files
set(MAIN_SOURCES 
    src/main.c)

# Util source files
set(UTIL_SOURCES 
    src/util/umath.c)

# Component source files
set(COMPONENT_SOURCES 
    src/component/translate.c
    src/component/sprite.c)

# Core source files
set(WORLD_SOURCES 
    src/world/grid.c)

# Entity source files
set(ENTITY_SOURCES 
    src/entity/player.c)

find_package(raylib 3.0 QUIET)

add_executable(${PROJECT_NAME} ${MAIN_SOURCES} ${UTIL_SOURCES} ${COMPONENT_SOURCES} ${WORLD_SOURCES} ${ENTITY_SOURCES})

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

target_link_libraries(${PROJECT_NAME} raylib)
