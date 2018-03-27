cmake_minimum_required(VERSION 3.0)

option(Testing "Build tests." OFF)

set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

set(PELMENI_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/pelmeni)
set(RAPIDJSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/rapidjson/include)

find_package(SFML 2 REQUIRED network audio graphics window system)

add_subdirectory(src)

if (Testing)
    add_subdirectory(test)
    add_subdirectory(external/googletest)
endif()
