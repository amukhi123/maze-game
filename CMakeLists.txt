cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

project("MazeGame")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC lib)

target_link_libraries(${PROJECT_NAME} PUBLIC C:/Users/Aqil/Documents/GitHub/maze-game/lib/raylib/raylibdll.lib)
