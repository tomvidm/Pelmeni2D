project(p2d-graphics)

set(SOURCES
    ../json/Helpers.cpp
    particles/Particle2D.cpp
    AnimatedSprite.cpp
    AnimationState.cpp
    Axes.cpp
    FrameSequence.cpp
    Hexagon.cpp
    SpritePackManager.cpp
    Sprite.cpp
    SpriteBase.cpp
    TextureManager.cpp
    Tilemap.cpp
    Mesh2D.cpp
    MeshData2D.cpp
    WireMesh.cpp
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${PELMENI_SRC_DIR}
    ${RAPIDJSON_INCLUDE_DIR}
    )

add_library(p2d-graphics
    ${SOURCES}
)

target_link_libraries(p2d-graphics
    p2d-animation
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-graphics
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
