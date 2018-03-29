project(p2d-debugging)

set(SOURCES
    LogContainer.cpp
    Logger.cpp
)

add_library(p2d-debugging
    ${SOURCES}
)

set_target_properties(p2d-debugging
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )