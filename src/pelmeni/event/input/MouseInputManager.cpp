#include "MouseInputManager.hpp"

namespace p2d { namespace event { namespace input {
    InputEvent MouseInputManager::onEvent(const sf::Event& sfmlEvent) {
        switch (sfmlEvent.type) {
            case sf::Event::EventType::MouseButtonPressed:
                return onMouseButtonEvent(sf::Event::EventType::MouseButtonPressed, 
                                          static_cast<MouseButton>(sfmlEvent.mouseButton.button));
            case sf::Event::EventType::MouseButtonReleased:
                return onMouseButtonEvent(sf::Event::EventType::MouseButtonReleased, 
                                          static_cast<MouseButton>(sfmlEvent.mouseButton.button));
            case sf::Event::EventType::MouseMoved:
                return onMouseMoveEvent(sfmlEvent.mouseMove.x,
                                        sfmlEvent.mouseMove.y);
            default:
                return InputEvent{};
        }// switch
    } // onEvent

    InputEvent MouseInputManager::onMouseButtonEvent(const sf::Event::EventType& sfmlEventType,
                                                     const MouseButton& mouseButton) {
        InputEvent inputEvent;
        inputEvent.eventType = InputEventType::MOUSEBUTTON;
        inputEvent.mouseButtonEvent = mouseState.onMouseButtonEvent(sfmlEventType, mouseButton);
    } // onMouseButtonEvent

    InputEvent MouseInputManager::onMouseMoveEvent(const int& x,
                                                   const int& y) {
        InputEvent inputEvent;
        inputEvent.eventType = InputEventType::MOUSEMOVE;
        inputEvent.mouseMoveEvent = mouseState.onMouseMoveEvent(x, y);
    } // onMouseButtonEvent
} // namespace input
} // namespace event
} // namespace p2d