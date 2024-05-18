cmake_minimum_required(VERSION 3.28)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

# Trouver SDL2
find_package(SDL2 REQUIRED)

# Inclure les headers SDL2
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(GameOfLife main.cpp)

# Lier SDL2
target_link_libraries(GameOfLife ${SDL2_LIBRARIES})