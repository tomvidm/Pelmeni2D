project(pelmeni)

add_subdirectory(pelmeni)

add_executable(p2d-run
    main.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${RAPIDJSON_INCLUDE_DIR}
    ${PELMENI_SRC_DIR}
)

target_link_libraries(p2d-run 
    p2d-system
)