#pragma once

#include "SFML/Graphics.hpp"
#include "math/Vector.hpp"

namespace p2d { namespace input {
    math::Vector2f getMousePosition(sf::RenderWindow& window);

    enum MouseButton {
        LEFT        = 0,
        RIGHT       = 1,
        MIDDLE      = 2,
        XBUTTON1    = 3,
        XBUTTON2    = 4,
        NUM_BUTTONS = 5
    }; // enum MouseButton
} // namespace input
} // namespace p2d