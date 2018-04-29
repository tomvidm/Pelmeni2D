project(p2d-system)

set(SOURCES
    ../json/Helpers.cpp
    BlueprintManager.cpp
    Entity.cpp
    EntityContainer.cpp
    EntityFactory.cpp
    EntityManager.cpp
    Instance.cpp
    Scene.cpp
    Transformable2.cpp
    Transformable3.cpp
)

include_directories(
    ${PELMENI_SRC_DIR}
    ${SFML_INCLUDE_DIR}
    ${RAPIDJSON_INCLUDE_DIR}
    )

add_library(p2d-system
    ${SOURCES}
)

target_link_libraries(p2d-system
    p2d-input
    p2d-graphics
    p2d-math
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-system
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
