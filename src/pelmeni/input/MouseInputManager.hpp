#pragma once

#include "SFML/Graphics.hpp"

#include "Mouse.hpp"
#include "MouseState.hpp"
#include "InputEvent.hpp"

namespace p2d { namespace input {
    class MouseInputManager {
    public:
        InputEvent onEvent(const sf::Event& sfmlEvent);
        InputEvent onMouseButtonEvent(const sf::Event::EventType& eventType,
                                      const MouseButton& mouseButton);
        InputEvent onMouseMoveEvent(const int& x,
                                    const int& y);
    private:
        MouseState mouseState;
    }; // MouseInputManager
} // namespace input
} // namespace p2d