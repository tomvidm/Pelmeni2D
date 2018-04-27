project(p2d-graphics)

set(SOURCES
    Axes.cpp
    AnimationState.cpp
    FrameSequence.cpp
    #FrameSequenceLoader.cpp
    #SpritePackage.cpp
    SpritePackManager.cpp
    Sprite.cpp
    Hexagon.cpp
    #Sprite3.cpp
    TextureManager.cpp
    Mesh2D.cpp
    MeshData2D.cpp
    Tilemap.cpp
    WireMesh.cpp
    ../json/Helpers.cpp
    particles/Particle2D.cpp
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
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-graphics
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
