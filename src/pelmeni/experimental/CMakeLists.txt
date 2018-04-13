project(p2d-experimental)

set(SOURCES
    Gish.cpp
)

include_directories(
    ${PELMENI_SRC_DIR}
    )

add_library(p2d-experimental
    ${SOURCES}
)

target_link_libraries(p2d-experimental
    p2d-math
    p2d-physics
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-experimental
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
