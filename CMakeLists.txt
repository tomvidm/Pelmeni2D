cmake_minimum_required(VERSION 3.0)

option(Testing "Build tests." OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

set(PELMENI_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)

if (Testing)
    add_subdirectory(test)
    add_subdirectory(external/googletest)
endif()
