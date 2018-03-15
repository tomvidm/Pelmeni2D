#pragma once

#include "Event.hpp"
#include "input/InputManager.hpp"

namespace p2d { namespace event {
    class EventManager {
    public:
        Event onSfmlEvent(const sf::Event& sfmlEvent);
    private:
        input::InputManager inputManager;
    }; // class EventManager
} // event
} // p2d