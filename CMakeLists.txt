cmake_minimum_required(VERSION 3.19)
project(TileGame)

set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 17)

# Main source files
set(MAIN_SOURCES 
    src/main.c
)

# Entity source files
set(ENTITY_SOURCES 
    src/entity/player.c
)

# Util source files
set(UTIL_SOURCES 
    src/util/u_math.c
    src/util/u_misc.c
    src/util/collision.c
)

# Component source files
set(COMPONENT_SOURCES 
    src/component/translate.c
    src/component/sprite.c
    src/component/collider.c
)

# Core source files
set(WORLD_SOURCES 
    src/world/tilemap.c)

add_executable(${PROJECT_NAME} ${MAIN_SOURCES} ${UTIL_SOURCES} ${COMPONENT_SOURCES} ${WORLD_SOURCES} ${ENTITY_SOURCES})

find_package(raylib 4.0.0 REQUIRED)
target_link_libraries(${PROJECT_NAME} raylib)
