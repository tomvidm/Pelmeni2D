#include "animation/Frame.hpp"

namespace p2d { namespace animation {
    bool operator == (const Frame& lhs, const Frame& rhs) {
        return lhs.position == rhs.position &&
               lhs.scale == rhs.scale &&
               lhs.angle == rhs.angle;
    }

    Frame operator + (const Frame& lhs, const Frame& rhs) {
        return Frame{
            lhs.position + rhs.position,
            lhs.scale + rhs.scale,
            lhs.angle + rhs.angle
        };
    }

    Frame operator - (const Frame& lhs, const Frame& rhs) {
        return Frame{
            lhs.position - rhs.position,
            lhs.scale - rhs.scale,
            lhs.angle - rhs.angle
        };
    }

    Frame operator * (const Frame& lhs, const float rhs) {
        return Frame{
            lhs.position * rhs,
            lhs.scale * rhs,
            lhs.angle * rhs
        };
    }
} // namespace animation
} // namespace p2d 