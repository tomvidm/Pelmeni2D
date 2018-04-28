#include "animation/Keyframe.hpp"

namespace p2d { namespace animation {
    bool operator == (const Keyframe& lhs, const Keyframe& rhs) {
        return lhs.duration == rhs.duration &&
               lhs.frame == rhs.frame;
    };
} // namespace animation
} // namespace p2d 