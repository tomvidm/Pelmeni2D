#include "MouseButtonState.hpp"

namespace p2d { namespace input {
    MouseButtonState::MouseButtonState() 
    : isPressed_(false) {
        clickInterval = sf::milliseconds(200);
        pressTimer.restart();
    } // constructor

    void MouseButtonState::press() {
        isPressed_ = true;
        pressTimer.restart();
    } // press

    void MouseButtonState::release() {
        isPressed_ = false;
    } // release

    MouseButtonEventType MouseButtonState::onPressEventType() const {
        return MouseButtonEventType::PRESS;
    }
    
    MouseButtonEventType MouseButtonState::onReleaseEventType() const {
        return MouseButtonEventType::RELEASE;
    }

    MouseButtonSecondaryEventType MouseButtonState::onPressSecondaryEventType() const {
        if (pressWillRegisterAsDoubleClick()) {
            return MouseButtonSecondaryEventType::DOUBLECLICK;
        } else return MouseButtonSecondaryEventType::NONE;
    }

    MouseButtonSecondaryEventType MouseButtonState::onReleaseSecondaryEventType() const {
        if (releaseWillRegisterAsClick()) {
            return MouseButtonSecondaryEventType::CLICK;
        } else return MouseButtonSecondaryEventType::NONE;
    }

    bool MouseButtonState::releaseWillRegisterAsClick() const {
        if (isPressed() &&
            pressTimer.getElapsedTime() < clickInterval) {
            return true;
        } // if
        return false;
    } // releaseWilLRegisterAsClick

    bool MouseButtonState::pressWillRegisterAsDoubleClick() const {
        if (!isPressed() &&
            pressTimer.getElapsedTime() < clickInterval) {
            return true;
        } // if
        return false;
    } // releaseWilLRegisterAsClick
} // namespace input
} // namespace p2d