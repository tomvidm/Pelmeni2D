project(pelmeni)

find_package(SFML 2 REQUIRED network audio graphics window system)

add_executable(pelmeni-run
    main.cpp
)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(pelmeni-run ${SFML_LIBRARIES})