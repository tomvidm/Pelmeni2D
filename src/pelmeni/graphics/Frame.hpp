#pragma once

#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Rect.hpp"

namespace p2d { namespace graphics {
    struct Frame {
        Frame(const sf::Time& t, const sf::Rect<int>& rect)
        : duration(t), frameRect(rect) {;}

        Frame(const sf::Time& t,
              const int x,
              const int y,
              const int xsize,
              const int ysize)
        : duration(t) {
            frameRect = sf::Rect<int>(x, y, xsize, ysize);
        }
        
        sf::Time duration;
        sf::Rect<int> frameRect;
    }; // struct Frame
} // namespace graphics
} // namespace p2d