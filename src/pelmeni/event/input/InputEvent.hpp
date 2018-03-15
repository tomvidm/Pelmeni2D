#pragma once

#include "MouseButtonEvent.hpp"
#include "MouseMoveEvent.hpp"

namespace p2d { namespace event { namespace input {
    enum InputEventType {
        MOUSEBUTTON,
        MOUSEMOVE
    };

    struct InputEvent {
        InputEventType eventType;
        union {
            MouseButtonEvent mouseButtonEvent;
            MouseMoveEvent mouseMoveEvent;
        };
    }; // class InputEvent
} // namespace input
} // namespace event
} // namespace p2d