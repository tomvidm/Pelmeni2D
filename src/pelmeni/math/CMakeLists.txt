project(p2d-math)

add_library(p2d-math
    math.cpp
    Vector.cpp
    Radian.cpp
    Transform.cpp
    Transform3.cpp
    )

set_target_properties(p2d-math
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )

include_directories(
    ${PELMENI_SRC_DIR}
)