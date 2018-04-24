project(tbsgame)

set(SOURCES
    main.cpp
)

include_directories(
    ${PELMENI_SRC_DIR}
    )

add_executable(tbsgame
    ${SOURCES}
)

target_link_libraries(tbsgame
    ${SFML_LIBRARIES}
)