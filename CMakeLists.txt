cmake_minimum_required(VERSION 2.6)

project(TEFGAS)

add_library(libs src/libs/Core.cpp)


add_executable(game src/game/main.cpp)

target_link_libraries(game libs)