#pragma once

#include "input/Mouse.hpp"

namespace p2d { namespace input {
    enum MouseButtonEventType {
        PRESS,
        RELEASE
    };

    enum MouseButtonSecondaryEventType {
        NONE,
        CLICK,
        DOUBLECLICK
    }; 

    struct MouseButtonEvent {
        MouseButton button;
        MouseButtonEventType eventType;
        MouseButtonSecondaryEventType secondaryEventType;

        bool operator == (const MouseButtonEvent& rhs) const;
    }; // struct MouseButtonEvent
} // namespace input
} // namespace p2d