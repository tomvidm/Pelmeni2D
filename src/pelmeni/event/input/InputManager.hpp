#pragma once

#include "MouseInputManager.hpp"

namespace p2d { namespace event { namespace input {
    class InputManager {
    public:
        InputEvent onEvent(const sf::Event& sfmlEvent);
    private:
        MouseInputManager mouseInputManager;
    }; // MouseInputManager
} // namespace input
} // namespace event
} // namespace p2d