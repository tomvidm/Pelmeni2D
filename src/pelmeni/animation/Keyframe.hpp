#pragma once

#include "SFML/System/Time.hpp"

#include "animation/Frame.hpp"

namespace p2d { namespace animation {
    struct Keyframe {
        sf::Time duration;
        Frame frame;
    }; // struct Keyframe
    
    bool operator == (const Keyframe& lhs, const Keyframe& rhs);
} // namespace animation
} // namespace p2d 