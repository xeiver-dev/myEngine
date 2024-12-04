cmake_minimum_required(VERSION 3.20)

project(mybe VERSION 0.01 LANGUAGES C) 

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES src/*.c)
include_directories(include)
include_directories(/usr/include)

add_executable(mybe ${SOURCES})
target_link_libraries(mybe SDL2 SDL2_ttf SDL2_image SDL2_net)
