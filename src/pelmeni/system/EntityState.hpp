#pragma once

#include "math/Transform3.hpp"
#include "math/Transform.hpp"

namespace p2d { namespace system {
    struct EntityState {
        union {
            math::Transform3 transform3;
            math::Transform transform2;
        };
    }; // struct EntityState
} // namespace system
} // namesapce p2d