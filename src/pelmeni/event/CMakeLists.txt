project(p2d-event)

set(SOURCES
    EventManager.cpp
)

add_subdirectory(input)

add_library(p2d-event
    ${SOURCES}
)

target_link_libraries(p2d-event
    p2d-input
)

set_target_properties(p2d-event
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )