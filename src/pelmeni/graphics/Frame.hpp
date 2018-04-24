#pragma once

#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Rect.hpp"

namespace p2d { namespace graphics {
    struct Frame {
        Frame(const sf::Time& t, const sf::Rect<float>& rect)
        : duration(t), frameRect(rect) {;}

        Frame(const sf::Time& t,
              const float x,
              const float y,
              const float xsize,
              const float ysize)
        : duration(t) {
            frameRect = sf::Rect<float>(x, y, xsize, ysize);
        }
        
        sf::Time duration;
        sf::Rect<float> frameRect;
    }; // struct Frame
} // namespace graphics
} // namespace p2d