#pragma once

#include "input/InputEvent.hpp"

namespace p2d { namespace input {
    class InputListener {
    public:
        virtual void onEvent(const input::InputEvent& event) = 0;
    }; // class Listener
} // namespace input
} // namespace p2d