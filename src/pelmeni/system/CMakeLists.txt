project(p2d-system)

set(SOURCES
    Instance.cpp
    State.cpp
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pelmeni
    )

add_library(p2d-system
    ${SOURCES}
)

target_link_libraries(p2d-system
    p2d-event
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-system
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
