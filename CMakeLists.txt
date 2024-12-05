cmake_minimum_required(VERSION 3.20)

project(myEngine VERSION 0.01 LANGUAGES C) 

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES src/*.c)
include_directories(include)
include_directories(/usr/include/SDL2)

add_executable(myEngine ${SOURCES})
target_link_libraries(myEngine SDL2 SDL2_ttf SDL2_image SDL2_net)
