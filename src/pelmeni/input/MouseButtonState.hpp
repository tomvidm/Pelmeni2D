#pragma once

#include "SFML/Graphics.hpp"

#include "input/Mouse.hpp"
#include "input/MouseButtonEvent.hpp"

namespace p2d { namespace input {
    class MouseButtonState {
    public:
        MouseButtonState();
        
        void press();
        void release();

        MouseButtonEventType onPressEventType() const;
        MouseButtonEventType onReleaseEventType() const;

        bool releaseWillRegisterAsClick() const;
        bool pressWillRegisterAsDoubleClick() const;
        inline bool isPressed() const { return isPressed_; }
        
        inline void setClickInterval(const sf::Time& interval) { clickInterval = interval; }
    private:
        bool isPressed_;

        sf::Time clickInterval;
        sf::Clock pressTimer;
    }; // class MouseState
} // namespace input
} // namespace p2d