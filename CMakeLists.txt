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
	src/Engine/stb_vorbis.cpp
	src/Engine/Camera.cpp
	src/Engine/Transform.cpp
	src/Engine/Material.cpp
	src/Engine/Time.cpp
	src/Engine/Sound.cpp
)

	include_directories(
	contrib/glm
	contrib/msvc-windows-x86/glew/include
	contrib/msvc-windows-x86/SDL2/include
	contrib/msvc-windows-x86/openal-soft/include
)

	link_directories(
	${CMAKE_SOURCE_DIR}/msvc-windows-x86/contrib/glew/lib
	${CMAKE_SOURCE_DIR}/msvc-windows-x86/contrib/SDL2/lib
	${CMAKE_SOURCE_DIR}/msvc-windows-x86/contrib/openal-soft/lib
)

	target_link_libraries(TEFGAS SDL2 opengl32 glew32 OpenAL32)

add_executable(game src/game/main.cpp src/game/CameraController.cpp src/game/LightMover.cpp src/game/Rotateymcboatface.cpp)

target_link_libraries(game TEFGAS)
