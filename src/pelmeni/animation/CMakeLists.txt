project(p2d-animation)

set(SOURCES
    Animable.cpp
    Animation.cpp
    Frame.cpp
    Keyframe.cpp
)

add_library(p2d-animation
    ${SOURCES}  
)

target_link_libraries(p2d-animation
    p2d-system
)

set_target_properties(p2d-animation
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )

include_directories(
    ${PELMENI_SRC_DIR}
)