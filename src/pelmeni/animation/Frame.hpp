#pragma once

#include "math/Vector.hpp"

namespace p2d { namespace animation {
    struct Frame {
        math::Vector2f position;
        math::Vector2f scale;
        math::Vector2f origin;
        math::Radian angle;
    }; // struct Frame

    bool operator == (const Frame& lhs, const Frame& rhs);
    Frame operator + (const Frame& lhs, const Frame& rhs);
    Frame operator - (const Frame& lhs, const Frame& rhs);
    Frame operator * (const Frame& lhs, const float rhs);
} // namespace animation
} // namespace p2d 