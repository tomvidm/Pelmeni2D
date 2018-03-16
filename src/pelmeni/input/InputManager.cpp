#include "InputManager.hpp"

namespace p2d { namespace input {
    void InputManager::collectInputEvents(sf::Window& window) {
        sf::Event sfmlEvent;
        while(window.pollEvent(sfmlEvent)) {
            InputEvent inputEvent = onEvent(sfmlEvent);

            if (inputEvent == InputEvent::Closed) {
                window.close();
            } // if
        } // while
    } // collectInputEvents

    void InputManager::notifyListeners(const InputEvent& inputEvent) {
        ;
    } // notifyListeners
 
    InputEvent InputManager::onEvent(const sf::Event& sfmlEvent) {
        switch (sfmlEvent.type) {
            case sf::Event::EventType::MouseButtonPressed:
            case sf::Event::EventType::MouseButtonReleased:
            case sf::Event::EventType::MouseMoved:
                return mouseInputManager.onEvent(sfmlEvent);
            case sf::Event::EventType::Closed:
                return InputEvent::Closed;
            default:
                return InputEvent{};
        }
    }
} // namespace input
} // namespace p2d