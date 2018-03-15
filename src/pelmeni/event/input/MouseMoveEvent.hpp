#pragma once

#include "Mouse.hpp"

namespace p2d { namespace event { namespace input {
    struct MouseMoveEvent {
        int xpos, ypos, xposRel, yposRel;
    }; // struct MouseButtonEvent
} // namespace input
} // namespace event
} // namespace p2d