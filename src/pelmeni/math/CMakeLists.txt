project(p2d-math)

add_library(p2d-math
    BezierCurve.cpp
    CatmullRomSpline.cpp
    ConvexPolygon.cpp
    graph/Graph.cpp
    graph/Node.cpp
    graph/Dijkstra.cpp
    graph/TilemapGraph.cpp
    math.cpp
    GeometrySelection.cpp
    Radian.cpp
    Random.cpp
    LineIntersection.cpp
    Transform.cpp
    Transform3.cpp
    Vector.cpp
    )

set_target_properties(p2d-math
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )

include_directories(
    ${PELMENI_SRC_DIR}
)