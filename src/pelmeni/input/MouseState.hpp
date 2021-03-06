#pragma once

#include "input/Mouse.hpp"
#include "input/MouseButtonState.hpp"
#include "input/MouseButtonEvent.hpp"
#include "input/MouseMoveEvent.hpp"

#include "math/Vector.hpp"

namespace p2d { namespace input {
    class MouseState {
    public:
        MouseButtonEvent onMouseButtonEvent(const sf::Event::EventType& sfmlEventType,
                                            const MouseButton& mouseButton);
        MouseMoveEvent onMouseMoveEvent(const int& mx, 
                                        const int& my);
    private:
        math::Vector2i mousePosition;
        MouseButtonState buttonState[static_cast<size_t>(MouseButton::NUM_BUTTONS)];
    }; // class MouseState
} // namespace input
} // namespace p2d