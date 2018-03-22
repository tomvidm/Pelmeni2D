project(p2d-ut)

set(GTEST_DIR ${CMAKE_SOURCE_DIR}/external/googletest/googletest)

set(TEST_SOURCES
    TrivialTest.cpp
    pelmeni/input/TestMouseButtonState.cpp
    pelmeni/input/TestMouseState.cpp
)


include_directories(
    ${gtest_SOURCE_DIR}
    ${gtest_SOURCE_DIR}/include
    ${PELMENI_SRC_DIR}
)

add_executable(
    p2d-ut
    ${GTEST_DIR}/src/gtest-all.cc
    ${TEST_SOURCES}
)

target_link_libraries(
    p2d-ut
    p2d-input
    gtest
    gtest_main
)