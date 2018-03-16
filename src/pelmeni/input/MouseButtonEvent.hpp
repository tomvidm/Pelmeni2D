#pragma once

#include "Mouse.hpp"

namespace p2d { namespace input {
    enum MouseButtonEventType {
        PRESS,
        CLICK,
        DOUBLECLICK,
        RELEASE
    };

    struct MouseButtonEvent {
        MouseButton button;
        MouseButtonEventType eventType;

        bool operator == (const MouseButtonEvent& rhs) const;
    }; // struct MouseButtonEvent
} // namespace input
} // namespace p2d