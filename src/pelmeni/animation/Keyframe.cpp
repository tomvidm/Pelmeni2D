#include "animation/Keyframe.hpp"

namespace p2d { namespace animation {
    bool operator == (const Keyframe& lhs, const Keyframe& rhs) {
        return lhs.position == rhs.position &&
               lhs.scale == rhs.scale &&
               lhs.angle == rhs.angle;
    }

    Keyframe operator + (const Keyframe& lhs, const Keyframe& rhs) {
        return Keyframe{
            lhs.position + rhs.position,
            lhs.scale + rhs.scale,
            lhs.angle + rhs.angle
        };
    }

    Keyframe operator - (const Keyframe& lhs, const Keyframe& rhs) {
        return Keyframe{
            lhs.position - rhs.position,
            lhs.scale - rhs.scale,
            lhs.angle - rhs.angle
        };
    }

    Keyframe operator * (const Keyframe& lhs, const float rhs) {
        return Keyframe{
            lhs.position * rhs,
            lhs.scale * rhs,
            lhs.angle * rhs
        };
    }
} // namespace animation
} // namespace p2d 