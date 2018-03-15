#pragma once

#include "Mouse.hpp"

namespace p2d { namespace event { namespace input {
    enum MouseButtonEventType {
        PRESS,
        CLICK,
        DOUBLECLICK,
        RELEASE
    };

    struct MouseButtonEvent {
        MouseButton button;
        MouseButtonEventType eventType;
    }; // struct MouseButtonEvent
} // namespace input
} // namespace event
} // namespace p2d