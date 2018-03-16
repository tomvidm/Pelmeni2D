#pragma once

#include "Mouse.hpp"

namespace p2d { namespace input {
    struct MouseMoveEvent {
        int xpos, ypos, xposRel, yposRel;
    }; // struct MouseButtonEvent
} // namespace input
} // namespace p2d