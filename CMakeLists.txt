cmake_minimum_required(VERSION 3.16)

project(heimdall VERSION 0.0.1)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(cxxopts REQUIRED)
pkg_check_modules(FMT REQUIRED fmt)
pkg_check_modules(SPDLOG REQUIRED spdlog)
pkg_check_modules(RAPIDJSON REQUIRED RapidJSON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Werror -Wall -Wextra -Wshadow -Wunknown-pragmas -Wformat=2 -Wsign-conversion -Wswitch-default -Wfloat-equal
    $<$<COMPILE_LANGUAGE:CXX>:-Weffc++>
    $<$<COMPILE_LANGUAGE:CXX>:-Wold-style-cast>
)

set(3RDPARTY_LIBRARIES
        ${FMT_LINK_LIBRARIES}
        ${SPDLOG_LINK_LIBRARIES}
        ${RAPIDJSON_LINK_LIBRARIES}
)

set(3RDPARTY_INCLUDES
        ${FMT_INCLUDE_DIRS}
        ${SPDLOG_INCLUDE_DIRS}
        ${RAPIDJSON_INCLUDE_DIRS}
)

add_subdirectory(src)
