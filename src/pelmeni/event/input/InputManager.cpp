#include "InputManager.hpp"

namespace p2d { namespace event { namespace input {
    InputEvent InputManager::onEvent(const sf::Event& sfmlEvent) {
        switch (sfmlEvent.type) {
            case sf::Event::EventType::MouseButtonPressed:
            case sf::Event::EventType::MouseButtonReleased:
            case sf::Event::EventType::MouseMoved:
                return mouseInputManager.onEvent(sfmlEvent);
            default:
                return InputEvent{};
        }
    }
} // namespace input
} // namespace event
} // namespace p2d