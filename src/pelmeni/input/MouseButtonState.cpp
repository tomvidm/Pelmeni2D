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
        if (pressWillRegisterAsDoubleClick()) {
            return MouseButtonEventType::DOUBLECLICK;
        } else {
            return MouseButtonEventType::PRESS;
        }
    }
    
    MouseButtonEventType MouseButtonState::onReleaseEventType() const {
        if (releaseWillRegisterAsClick()) {
            return MouseButtonEventType::CLICK;
        } else {
            return MouseButtonEventType::RELEASE;
        }
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