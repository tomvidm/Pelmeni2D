project(p2d-input)

set(SOURCES
    Mouse.cpp
    MouseButtonState.cpp
    MouseButtonEvent.cpp
    MouseInputManager.cpp
    MouseState.cpp
    InputEvent.cpp
    InputManager.cpp
)

add_library(p2d-input
    ${SOURCES}
)

include_directories(
    ${SFML_INCLUDE_DIR}
    ${PELMENI_SRC_DIR}
)

target_link_libraries(p2d-input
    ${SFML_LIBRARIES}
)

set_target_properties(p2d-input
    PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    )