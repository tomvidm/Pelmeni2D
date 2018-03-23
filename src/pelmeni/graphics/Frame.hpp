#pragma once

#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Rect.hpp"

namespace p2d { namespace graphics {
    struct Frame {
        Frame(const sf::Time& t, const sf::Rect<int>& rect)
        : duration(t), frameRect(rect) {;}
        
        sf::Time duration;
        sf::Rect<int> frameRect;
    }; // struct Frame
} // namespace graphics
} // namespace p2d