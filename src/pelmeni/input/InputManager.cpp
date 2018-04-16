#include "InputManager.hpp"

namespace p2d { namespace input {
    void InputManager::collectInputEvents(sf::RenderWindow& window) {
        sf::Event sfmlEvent;
        while(window.pollEvent(sfmlEvent)) {
            inputEvents.push_back(std::move(onEvent(sfmlEvent, window)));
        } // while
    } // collectInputEvents

    void InputManager::notifyListeners() {
        for (auto& event : inputEvents) {
            auto eventType = event.eventType;
            for (auto listener = eventListenerMap.lower_bound(eventType); listener != eventListenerMap.upper_bound(eventType); listener++) {
                (*listener).second->onEvent(event);
            }
        }
        inputEvents.clear();
    } // notifyListeners

    void InputManager::registerListener(const InputEventType& eventType, InputListener* listener) {
        eventListenerMap.insert(std::make_pair(eventType, listener));
    }
 
    InputEvent InputManager::onEvent(const sf::Event& sfmlEvent, sf::RenderWindow& window) {
        InputEvent inputEvent;
        switch (sfmlEvent.type) {
            case sf::Event::EventType::MouseMoved:
            case sf::Event::EventType::MouseButtonPressed:
            case sf::Event::EventType::MouseButtonReleased:
                inputEvent = std::move(mouseInputManager.onEvent(sfmlEvent));
                break;
            case sf::Event::EventType::Closed:
                window.close();
                inputEvent = std::move(InputEvent::Closed);
                break;
            default:
                break;
        }
        inputEvent.window = &window;
        return inputEvent;
    }
} // namespace input
} // namespace p2d