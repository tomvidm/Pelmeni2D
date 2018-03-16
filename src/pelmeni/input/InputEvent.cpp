#include "InputEvent.hpp"

namespace p2d { namespace input {
    const InputEvent InputEvent::Closed(InputEventType::WINDOW_CLOSED);

    InputEvent::InputEvent() {;}

    InputEvent::InputEvent(const InputEventType& eventType) 
    : eventType(eventType) {;} // constructor

    bool InputEvent::operator == (const InputEvent& rhs) const {
        if (eventType == rhs.eventType) {
            switch (eventType) {
                case InputEventType::WINDOW_CLOSED:
                    return true;
                case InputEventType::MOUSEBUTTON:
                    return mouseButtonEvent == rhs.mouseButtonEvent;
                default:
                    return false;
            }
        } else {
            return false;
        }
    } // operator ==

    bool InputEvent::operator < (const InputEvent& rhs) const {
        return reinterpret_cast<long>(this) < reinterpret_cast<long>(&rhs);
    }
} // namespace input
} // namespace p2d