#include "input/MouseButtonEvent.hpp"

namespace p2d { namespace input {
    bool MouseButtonEvent::operator == (const MouseButtonEvent& rhs) const {
        if (button == rhs.button && 
            eventType == rhs.eventType && 
            secondaryEventType == rhs.secondaryEventType) {
            return true;
        } else { 
            return false;
        }
    }
} // namespace input
} // namespace p2d