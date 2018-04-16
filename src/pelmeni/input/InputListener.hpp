#pragma once

#include "input/InputEvent.hpp"

namespace p2d { namespace input {
    class InputListener {
    public:
        virtual void onEvent(const input::InputEventType& eventType) = 0;
    }; // class Listener
} // namespace input
} // namespace p2d