#include "input/MouseState.hpp"

namespace p2d { namespace input {
    MouseButtonEvent MouseState::onMouseButtonEvent(const sf::Event::EventType& sfmlEventType,
                                                    const MouseButton& mouseButton) {
        MouseButtonEvent mouseButtonEvent;
        mouseButtonEvent.button = mouseButton;
        if (sfmlEventType == sf::Event::EventType::MouseButtonPressed) {
            mouseButtonEvent.eventType = buttonState[mouseButton].onPressEventType();
            buttonState[mouseButton].press();
        } else if (sfmlEventType == sf::Event::EventType::MouseButtonReleased) {
            mouseButtonEvent.eventType = buttonState[mouseButton].onReleaseEventType();
            buttonState[mouseButton].release();
        } // else if
        return mouseButtonEvent;
    } // onMouseButtonEvent

    MouseMoveEvent MouseState::onMouseMoveEvent(const int& mx, 
                                                const int& my) {
        //math::Vector2i newMousePosition = math::Vector2i(mx, my);
        MouseMoveEvent event{
            mx,
            my,
            mx - mousePosition.x,
            my - mousePosition.y
        };
        mousePosition = math::Vector2i(mx, my);
        return event;
    } // onMouseMoveEvent
} // namespace input
} // namespace p2d