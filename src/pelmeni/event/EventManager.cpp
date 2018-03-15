#include "EventManager.hpp"

namespace p2d { namespace event {
        Event EventManager::onSfmlEvent(const sf::Event& sfmlEvent) {
            Event event;
            event.type = EventType::INPUT,
            event.inputEvent = inputManager.onEvent(sfmlEvent);
            return event;
        } // onSfmlEvent
} // event
} // p2d