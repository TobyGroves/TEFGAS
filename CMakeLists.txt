cmake_minimum_required(VERSION 2.6)

project(TEFGAS)

include_directories(src)

add_library(Engine
 	src/Engine/Core.cpp
 	src/Engine/Entity.cpp
 	src/Engine/Component.cpp
	src/Engine/Keyboard.cpp
	src/Engine/Environment.cpp
)

add_executable(game src/game/main.cpp)

target_link_libraries(game Engine)