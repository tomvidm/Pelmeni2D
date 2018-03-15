project(pelmeni)

find_package(SFML 2 REQUIRED network audio graphics window system)

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
    ${SFML_LIBRARIES}
)