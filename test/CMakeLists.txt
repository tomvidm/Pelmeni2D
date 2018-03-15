project(p2d-ut)

set(TEST_SOURCES
    TrivialTest.cpp
    #PoolTests.cpp
    #MouseButtonStateTests.cpp
)

message(STATUS ${GTEST_DIR} ${GTEST_ROOT})

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/pelmeni
)

add_executable(
    p2d-ut
    ${TEST_SOURCES}
)

target_link_libraries(
    p2d-ut
    p2d-event
    gtest
)