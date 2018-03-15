#pragma once

#include "input/InputEvent.hpp"

namespace p2d { namespace event {
    enum EventType {
        INPUT
    };
    
    struct Event {
        EventType type;
        union {
            input::InputEvent inputEvent;
        };
    }; // class EventManager
} // event
} // p2d