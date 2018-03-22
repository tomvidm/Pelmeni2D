project(pelmeni)

add_subdirectory(pelmeni)

add_executable(p2d-run
    main.cpp
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(p2d-run 
    p2d-system
    p2d-graphics
    ${SFML_LIBRARIES}
)