#pragma once

#include "math/Vector.hpp"

namespace p2d { namespace animation {
    struct Keyframe {
        math::Vector2f position;
        math::Vector2f scale;
        math::Radian angle;
    }; // struct Keyframe

    bool operator == (const Keyframe& lhs, const Keyframe& rhs);
    Keyframe operator + (const Keyframe& lhs, const Keyframe& rhs);
    Keyframe operator - (const Keyframe& lhs, const Keyframe& rhs);
    Keyframe operator * (const Keyframe& lhs, const float rhs);
} // namespace animation
} // namespace p2d 