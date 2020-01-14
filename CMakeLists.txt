cmake_minimum_required(VERSION 2.6)

project(TEFGAS)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

add_library(TEFGAS
 	src/Engine/Core.cpp
 	src/Engine/Entity.cpp
 	src/Engine/Component.cpp
	src/Engine/Keyboard.cpp
	src/Engine/Environment.cpp
    src/Engine/ShaderProgram.cpp
    src/Engine/VertexBuffer.cpp
    src/Engine/VertexArray.cpp
	src/Engine/RenderTexture.cpp
	src/Engine/RenderComponent.cpp
	src/Engine/Exception.cpp
	src/Engine/Mesh.cpp
	src/Engine/Texture.cpp
	src/Engine/stb_image.cpp
	src/Engine/Camera.cpp
	src/Engine/Transform.cpp
	src/Engine/Material.cpp
	src/Engine/Time.cpp
)

if(WIN32) # windows

	include_directories(
	contrib/glm
	contrib/msvc-windows-x86/glew/include
	contrib/msvc-windows-x86/SDL2/include
)

	link_directories(
	${CMAKE_SOURCE_DIR}/msvc-windows-x86/contrib/glew/lib
	${CMAKE_SOURCE_DIR}/msvc-windows-x86/contrib/SDL2/lib
)

	target_link_libraries(TEFGAS SDL2 opengl32 glew32)


else() # linux

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(TEFGAS ${SDL2_LIBRARIES} ${GLEW_LIBRARIES} ${OPENGL_LIBRARY} ${GLM_LIBRARIES})

endif()

add_executable(game src/game/main.cpp src/game/CameraController.cpp src/game/LightMover.cpp src/game/Rotateymcboatface.cpp)

target_link_libraries(game TEFGAS)
