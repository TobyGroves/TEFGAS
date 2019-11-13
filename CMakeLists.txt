cmake_minimum_required(VERSION 2.6)

project(TEFGAS)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

add_library(Engine
 	src/Engine/Core.cpp
 	src/Engine/Entity.cpp
 	src/Engine/Component.cpp
	src/Engine/Keyboard.cpp
	src/Engine/Environment.cpp
    src/Engine/MeshRenderer.cpp
    src/Engine/ShaderProgram.cpp
    src/Engine/VertexBuffer.cpp
    src/Engine/VertexArray.cpp
	src/Engine/Exception.cpp
	src/Engine/Model.cpp
	src/Engine/Mesh.cpp
	src/Engine/Texture.cpp
	src/Engine/stb_image.cpp
	src/Engine/Camera.cpp
	src/Engine/Transform.cpp
)

if(WIN32) # windows

	include_directories(
    		contrib/msvc-2017-windows-x86/glew/include
    		contrib/msvc-2017-windows-x86/SDL2/include
			contrib/glm
			contrib/assimp-3.1.1/include
  	)

	link_directories(
    		${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/SDL2/lib
    		${CMAKE_SOURCE_DIR}/contrib/msvc-2017-windows-x86/glew/lib
			${CMAKE_SOURCE_DIR}/contrib/glm
  	)

	target_link_libraries(Engine SDL2 glew32 opengl32 glm assimp)


else() # linux

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(ASSIMP REQUIRED)
include_directories(${ASSIMP_INCLUDE_DIRS})

target_link_libraries(Engine ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARY} ${GLM_LIBRARIES} ${ASSIMP_LIBRARIES})

endif()


add_executable(game src/game/main.cpp)

target_link_libraries(game Engine)
