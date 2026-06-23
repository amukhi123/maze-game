cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

project("MazeGame")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME})

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

target_sources(${PROJECT_NAME} PRIVATE ${SRC_FILES})

set(EXTERNAL_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(INTERNAL_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(
  ${PROJECT_NAME} PUBLIC 
  ${EXTERNAL_HEADERS}
  ${INTERNAL_HEADERS}
)

target_link_libraries(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib/raylibdll.lib")
