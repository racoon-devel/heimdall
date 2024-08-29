cmake_minimum_required(VERSION 3.16)

project(heimdall VERSION 1.0.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Werror -Wall -Wextra -Wshadow -Wunknown-pragmas -Wformat=2 -Wsign-conversion -Wswitch-default -Wfloat-equal
    $<$<COMPILE_LANGUAGE:CXX>:-Weffc++>
    $<$<COMPILE_LANGUAGE:CXX>:-old-style-cast>
)

add_subdirectory(src)
