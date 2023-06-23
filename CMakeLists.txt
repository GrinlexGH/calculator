cmake_minimum_required(VERSION 3.1)

if(NOT "${CMAKE_GENERATOR}" STREQUAL "MinGW Makefiles")
    message(FATAL_ERROR "Unsupported generator selected! Please use MinGW Makefiles.")
endif()

project(Calculator)

set(CMAKE_C_COMPILER "gcc" CACHE INTERNAL "" FORCE)
message(STATUS "C compiler: ${CMAKE_C_COMPILER}")
set(CMAKE_CXX_COMPILER "g++" CACHE INTERNAL "" FORCE)
message(STATUS "CXX compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Version: ${CMAKE_CXX_COMPILER_VERSION}")

if(NOT CMAKE_C_COMPILER MATCHES ".*gcc.*" OR NOT CMAKE_CXX_COMPILER MATCHES ".*g\\+\\+.*")
	message(FATAL_ERROR "Requires g++ and gcc compilers.")
endif()

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    if (CMAKE_C_COMPILER_VERSION VERSION_LESS "11.4")
        message(FATAL_ERROR "Requires GCC version 11.4 or higher!")
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "11.4")
        message(FATAL_ERROR "Requires G++ version 11.4 or higher!")
    endif()
endif()

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Werror)

set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SOURCES
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})