project(tbsgame)

set(SOURCES
    main.cpp
)

include_directories(
    ${PELMENI_SRC_DIR}
    ${RAPIDJSON_INCLUDE_DIR}
    )

add_executable(tbsgame
    ${SOURCES}
)

target_link_libraries(tbsgame
    ${SFML_LIBRARIES}
    p2d-system
    p2d-graphics
    p2d-input
)