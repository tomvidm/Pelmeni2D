#pragma once

#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Rect.hpp"

namespace p2d { namespace graphics {
    struct Frame {
        sf::Time duration;
        sf::Rect<float> frameRect;
    } // struct Frame
} // namespace graphics
} // namespace p2d