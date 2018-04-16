#include "InputManager.hpp"

namespace p2d { namespace input {
    void InputManager::collectInputEvents(sf::Window& window) {
        sf::Event sfmlEvent;
        while(window.pollEvent(sfmlEvent)) {
            inputEvents.push_back(std::move(onEvent(sfmlEvent, window)));
        } // while
    } // collectInputEvents

    void InputManager::notifyListeners() {
        for (auto& event : inputEvents) {
            auto eventType = event.eventType;
            for (auto listener = eventListenerMap.lower_bound(eventType); listener != eventListenerMap.upper_bound(eventType); listener++) {
                (*listener).second->onEvent(eventType);
            }
        }
    } // notifyListeners

    void InputManager::registerListener(const InputEventType& eventType, InputListener* listener) {
        eventListenerMap.insert(std::make_pair(eventType, listener));
    }
 
    InputEvent InputManager::onEvent(const sf::Event& sfmlEvent, sf::Window& window) {
        switch (sfmlEvent.type) {
            case sf::Event::EventType::MouseButtonPressed:
            case sf::Event::EventType::MouseButtonReleased:
            case sf::Event::EventType::MouseMoved:
                return mouseInputManager.onEvent(sfmlEvent);
            case sf::Event::EventType::Closed:
                window.close();
                return InputEvent::Closed;
            default:
                return InputEvent{};
        }
    }
} // namespace input
} // namespace p2d