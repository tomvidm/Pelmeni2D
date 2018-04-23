#include <cstdio>

#include "input/Mouse.hpp"

namespace p2d { namespace input {
    math::Vector2f getMousePosition(sf::RenderWindow& window) {
        const math::Vector2i pixel_pos = sf::Mouse::getPosition(window);
        const math::Vector2f screen_pos = window.mapPixelToCoords(pixel_pos);
        return screen_pos;
    }
} // namespace input
} // namespace p2d