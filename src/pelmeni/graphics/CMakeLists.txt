project(p2d-graphics)

set(SOURCES
    AnimationState.cpp
    FrameSequence.cpp
    #FrameSequenceLoader.cpp
    #SpritePackage.cpp
    #SpritePackageManager.cpp
    #Sprite.cpp
    TextureManager.cpp
    ../json/Helpers.cpp
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
