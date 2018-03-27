project(p2d-system)

set(SOURCES
    BlueprintManager.cpp
    BlueprintLoader.cpp
    Instance.cpp
    Object.cpp
    ObjectLoader.cpp
    ObjectManager.cpp
    State.cpp
    ../json/Helpers.cpp
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
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-system
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )
