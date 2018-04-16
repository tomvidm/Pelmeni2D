#pragma once

#include "MouseButtonEvent.hpp"
#include "MouseMoveEvent.hpp"

namespace sf {
    class RenderWindow;
}

namespace p2d { namespace input {
    enum InputEventType {
        WINDOW_CLOSED,
        MOUSEBUTTON,
        MOUSEMOVE
    };

    struct InputEvent {
        InputEvent();
        InputEvent(const InputEventType& eventType);

        static const InputEvent Closed;

        sf::RenderWindow* window;
        InputEventType eventType;
        union {
            MouseButtonEvent mouseButtonEvent;
            MouseMoveEvent mouseMoveEvent;
        };

        // comparison operator for simpler and cleaner unit testing
        bool operator == (const InputEvent& rhs) const;
        bool operator < (const InputEvent& rhs) const;
    }; // class InputEvent
} // namespace input
} // namespace p2d