project(p2d-gui)

set(SOURCES
    Widget.cpp
    WidgetStyle.cpp
    WidgetOptions.cpp
)

add_library(p2d-gui
    ${SOURCES}
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${PELMENI_SRC_DIR}
)

set_target_properties(p2d-gui
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )