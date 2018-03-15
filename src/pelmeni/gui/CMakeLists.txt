project(p2d-gui)

set(SOURCES
    Widget.cpp
)

add_library(p2d-gui
    ${SOURCES}
)

set_target_properties(p2d-gui
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )