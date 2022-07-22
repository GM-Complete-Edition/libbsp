cmake_minimum_required(VERSION 3.22)

project(libbsp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_library(
	libbsp 
	src/BSP.cpp src/Decoder.cpp src/MemoryStream.cpp src/Chunks/ChunkHeader.cpp src/Chunks/ModelPart.cpp src/Primitives/Rgba.cpp src/Primitives/Vector3.cpp
)
target_include_directories(libbsp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_compile_options(libbsp PRIVATE /W4)
else()
	target_compile_options(libbsp PRIVATE -Wall -Wextra -Wpedantic)
endif()
