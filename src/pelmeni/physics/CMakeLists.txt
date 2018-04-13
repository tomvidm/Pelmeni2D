project(p2d-physics)

set(SOURCES
    Body2D.cpp
    Physics.cpp
    Spring2D.cpp
)

include_directories(
    ${PELMENI_SRC_DIR}
    )

add_library(p2d-physics
    ${SOURCES}
)

target_link_libraries(p2d-physics
    p2d-math
    p2d-system
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-physics
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
