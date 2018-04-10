project(pelmeni)

add_subdirectory(pelmeni)

add_executable(p2d-run
    main.cpp
    testapps/Testapp_WireMesh.cpp
    testapps/Testapp_Sprites.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${RAPIDJSON_INCLUDE_DIR}
    ${PELMENI_SRC_DIR}
)

target_link_libraries(p2d-run 
    p2d-graphics
    p2d-system
    p2d-math
)