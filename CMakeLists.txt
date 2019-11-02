cmake_minimum_required(VERSION 2.6)

project(TEFGAS)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

add_library(Engine
 	src/Engine/Core.cpp
 	src/Engine/Entity.cpp
 	src/Engine/Component.cpp
	src/Engine/RenderComponent.cpp
	src/Engine/Keyboard.cpp
	src/Engine/Environment.cpp
)

add_executable(game src/game/main.cpp)

target_link_libraries(game Engine ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARY})
