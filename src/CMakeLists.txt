project(pelmeni)

add_subdirectory(pelmeni)
add_subdirectory(tbsgame)
add_subdirectory(platformgame)

add_executable(p2d-run
    main.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${RAPIDJSON_INCLUDE_DIR}
    ${PELMENI_SRC_DIR}
)

target_link_libraries(p2d-run 
    p2d-animation
    p2d-graphics
    p2d-experimental
    p2d-system
    p2d-math
    p2d-physics
    p2d-input
    p2d-gui
)