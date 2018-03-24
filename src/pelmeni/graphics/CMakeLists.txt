project(p2d-graphics)

set(SOURCES
    AnimationState.cpp
    FrameSequence.cpp
    Package.cpp
    PackageLoader.cpp
    PackageManager.cpp
    Sprite.cpp
    TextureLoader.cpp
    TextureManager.cpp
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pelmeni
    ${LUA_INCLUDE_DIR}
    ${LUA_SELENE_DIR}
    )

add_library(p2d-graphics
    ${SOURCES}
)

target_link_libraries(p2d-graphics
    ${SFML_LIBRARIES}
    ${LUA_LIBRARIES}
)

set_target_properties(p2d-graphics
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
