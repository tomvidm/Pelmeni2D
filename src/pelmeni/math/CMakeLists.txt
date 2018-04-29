project(p2d-math)

add_library(p2d-math
    math.cpp
    BezierCurve.cpp
    CatmullRomSpline.cpp
    Vector.cpp
    Radian.cpp
    Random.cpp
    Transform.cpp
    Transform3.cpp
    graph/Graph.cpp
    graph/Node.cpp
    graph/Dijkstra.cpp
    graph/TilemapGraph.cpp
    geometry/Hexagon.cpp
    )

set_target_properties(p2d-math
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )

include_directories(
    ${PELMENI_SRC_DIR}
)