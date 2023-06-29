cmake_minimum_required(VERSION 3.5)

if(NOT "${CMAKE_GENERATOR}" STREQUAL "MinGW Makefiles")
	message(FATAL_ERROR "Unsupported generator selected! Please use MinGW Makefiles.")
endif()

project(calculator)

set(CMAKE_C_COMPILER "gcc" CACHE INTERNAL "" FORCE)
message(STATUS "C compiler: ${CMAKE_C_COMPILER}")
set(CMAKE_CXX_COMPILER "g++" CACHE INTERNAL "" FORCE)
message(STATUS "CXX compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Version: ${CMAKE_CXX_COMPILER_VERSION}")

if(NOT CMAKE_C_COMPILER MATCHES ".*gcc.*" OR NOT CMAKE_CXX_COMPILER MATCHES ".*g\\+\\+.*")
	message(FATAL_ERROR "Requires g++ and gcc compilers.")
endif()

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_compile_options(-g -Og)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	add_compile_options(-Ofast)
endif()

set(CMAKE_EXE_LINKER_FLAGS "-lstdc++ -static -ffunction-sections -fdata-sections -Wl,--gc-sections")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Release)
endif()

set(SOURCES
	src/main.cpp
	src/console.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/src/resources ${CMAKE_BINARY_DIR}/Debug/resources
	)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/src/resources ${CMAKE_BINARY_DIR}/Release/resources
	)
endif()