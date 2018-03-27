project(p2d-system)

set(SOURCES
    Instance.cpp
    Object.cpp
    ObjectLoader.cpp
    ObjectManager.cpp
    State.cpp
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pelmeni
    ${LUA_INCLUDE_DIR}
    ${LUA_SELENE_DIR}
    )

add_library(p2d-system
    ${SOURCES}
    ${RAPIDJSON_INCLUDE_DIRs}
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
