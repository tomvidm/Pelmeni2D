#pragma once

#include <vector>

#include "SFML/System/Time.hpp"

namespace p2d { namespace animation {
    struct Keyframe {
        int deleteThisVar;
    };

    class Animation {
    private:
        std::vector<Keyframe> keyframes;
    }; // class Animation
} // namespace animation
} // namespace p2d